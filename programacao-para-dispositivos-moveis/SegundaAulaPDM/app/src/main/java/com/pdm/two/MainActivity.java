package com.pdm.two;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Parcelable;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// Busca os valores da tela
		EditText username = findViewById(R.id.input_username);
		EditText password = findViewById(R.id.input_password);

		// Busca o botão
		Button buttonLogin = findViewById(R.id.button_login);

		// Executa a ação de trocar de tela enviando parâmetros quando o botão é clicado
		buttonLogin.setOnClickListener(event -> {
			Intent intent = new Intent(this, Dashboard.class);

			intent.putExtra("username", username.getText().toString());
			intent.putExtra("password", password.getText().toString());
			startActivity(intent);
		});
	}
}