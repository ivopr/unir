package com.pdm.rivaldalocaliza.activities;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.snackbar.Snackbar;
import com.pdm.rivaldalocaliza.R;
import com.pdm.rivaldalocaliza.api.API;
import com.pdm.rivaldalocaliza.api.services.AuthenticationService;
import com.pdm.rivaldalocaliza.models.Authentication;
import com.pdm.rivaldalocaliza.models.LoginForm;
import com.pdm.rivaldalocaliza.models.RefreshForm;
import com.pdm.rivaldalocaliza.room.AppDb;
import com.pdm.rivaldalocaliza.room.Database;
import com.pdm.rivaldalocaliza.room.models.User;
import com.pdm.rivaldalocaliza.room.models.UserSession;
import com.pdm.rivaldalocaliza.utils.NetworkUtils;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class LoginActivity extends AppCompatActivity {
	AppDb database;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_login);

		database = Database.getDatabase(this);
		verifyUserLoggedIn(findViewById(android.R.id.content));

		Button executeLogin = findViewById(R.id.login_execute);
		TextView username = findViewById(R.id.login_username);
		TextView password = findViewById(R.id.login_password);

		executeLogin.setOnClickListener(view -> {
			if (username.getText().toString().isEmpty() || password.getText().toString().isEmpty()) {
				Snackbar
					.make(view, "Seu email e senha não podem ser vazios", Snackbar.LENGTH_LONG)
					.setBackgroundTint(
						getResources().getColor(R.color.red_500, getTheme()))
					.show();
			} else {
				API api = new API();
				AuthenticationService authenticationService = api.getAuthenticationService();

				if (NetworkUtils.hasInternetConnection(LoginActivity.this)) {
					(authenticationService.authenticate(
						new LoginForm(
							username.getText().toString(),
							password.getText().toString()
						)
					)).enqueue(new Callback<Authentication>() {
						@Override
						public void onResponse(Call<Authentication> call, Response<Authentication> response) {
							if (response.code() == 400) {
								Snackbar
									.make(view, "E-mail ou Senha incorretos", Snackbar.LENGTH_LONG)
									.setBackgroundTint(
										getResources().getColor(R.color.red_500, getTheme()))
									.show();
							} else if (response.code() == 200) {
								assert response.body() != null;
								List<UserSession> userSessions = database.getUserSessionDAO().getSessions();
								List<User> users = database.getUserDAO().getUsers();

								if (userSessions.size() > 0) {
									UserSession sessionToUpdate = userSessions.get(0);
									User userToUpdate = users.get(0);

									sessionToUpdate.setToken(response.body().getToken());
									sessionToUpdate.setRefresh_token(response.body().getRefresh_token());

									userToUpdate.setEmail(response.body().getUser().getEmail());
									userToUpdate.setName(response.body().getUser().getName());

									database.getUserSessionDAO().update(sessionToUpdate);
									database.getUserDAO().update(userToUpdate);
								} else {
									UserSession newUserSession = new UserSession();
									User newUser = new User();
									List<User> usersOnDB = database.getUserDAO().getUsers();

									newUserSession.setToken(response.body().getToken());
									newUserSession.setRefresh_token(response.body().getRefresh_token());

									newUser.setName(response.body().getUser().getName());
									newUser.setEmail(response.body().getUser().getEmail());

									database.getUserSessionDAO().insert(newUserSession);
									if (!usersOnDB.isEmpty()) {
										User userToUpdate = users.get(0);
										userToUpdate.setEmail(newUser.getEmail());
										userToUpdate.setName(newUser.getName());

										database.getUserDAO().update(userToUpdate);
									} else {
										database.getUserDAO().insert(newUser);
									}
								}

								username.setText("");
								password.setText("");

								Intent intent = new Intent(LoginActivity.this, MyLoanedCarActivity.class);
								startActivity(intent);
							}
						}

						@Override
						public void onFailure(Call<Authentication> call, Throwable t) {
							Snackbar
								.make(view, "Não foi possível conectar ao servidor", Snackbar.LENGTH_LONG)
								.setBackgroundTint(
									getResources().getColor(R.color.red_500, getTheme()))
								.show();
						}
					});
				} else {
					Snackbar
						.make(view, "Não há conexão ativa com a internet", Snackbar.LENGTH_LONG)
						.show();
				}
			}
		});
	}

	private void verifyUserLoggedIn(View view) {
		List<UserSession> sessions = database.getUserSessionDAO().getSessions();

		if (sessions.size() > 0) {
			UserSession session = sessions.get(0);

			API api = new API();
			AuthenticationService authenticationService = api.getAuthenticationService();

			(authenticationService.reAuthenticate(new RefreshForm(session.getRefresh_token())))
				.enqueue(new Callback<Authentication>() {
				@Override
				public void onResponse(Call<Authentication> call, Response<Authentication> response) {

					if (response.code() == 400) {
						database.getUserSessionDAO().delete(session);
						Snackbar
							.make(view, "Não foi possível revalidar seus dados, por favor, conecte-se novamente.", Snackbar.LENGTH_LONG)
							.setBackgroundTint(
								getResources().getColor(R.color.red_500, getTheme()))
							.show();
					} else {
						assert response.body() != null;
						session.setToken(response.body().getToken());
						session.setRefresh_token(response.body().getRefresh_token());
						database.getUserSessionDAO().update(session);

						Intent intent = new Intent(LoginActivity.this, MyLoanedCarActivity.class);
						startActivity(intent);
					}
				}

				@Override
				public void onFailure(Call<Authentication> call, Throwable t) {
					Snackbar
						.make(view, "Não foi possível revalidar seus dados, por favor, conecte-se novamente.", Snackbar.LENGTH_LONG)
						.setBackgroundTint(
							getResources().getColor(R.color.red_500, getTheme()))
						.show();
				}
			});
		}
	}
}