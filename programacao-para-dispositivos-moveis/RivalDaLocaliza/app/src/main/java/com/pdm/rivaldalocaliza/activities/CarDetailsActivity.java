package com.pdm.rivaldalocaliza.activities;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.google.android.material.snackbar.Snackbar;
import com.pdm.rivaldalocaliza.R;
import com.pdm.rivaldalocaliza.api.API;
import com.pdm.rivaldalocaliza.api.services.RentService;
import com.pdm.rivaldalocaliza.models.Car;
import com.pdm.rivaldalocaliza.models.RentCar;
import com.pdm.rivaldalocaliza.models.RentCarRet;
import com.pdm.rivaldalocaliza.room.AppDb;
import com.pdm.rivaldalocaliza.room.Database;
import com.pdm.rivaldalocaliza.room.models.UserSession;

import java.util.Calendar;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class CarDetailsActivity extends AppCompatActivity {
	AppDb database;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_car_details);

		Bundle bundle = getIntent().getExtras();
		String carId = bundle.getString("carId");

		database = Database.getDatabase(this);

		API api = new API();
		RentService rentService = api.getRentService();

		ImageView image = findViewById(R.id.details_image);
		TextView category = findViewById(R.id.details_category);
		TextView daily_fine = findViewById(R.id.details_daily_fine);
		TextView daily_price = findViewById(R.id.details_daily_price);
		TextView model = findViewById(R.id.details_model);
		Button rent = findViewById(R.id.details_rent);

		UserSession userSession = database.getUserSessionDAO().getSessions().get(0);

		(rentService.getCar("Bearer " + userSession.getToken(), carId)).enqueue(new Callback<Car>() {
			@SuppressLint("SetTextI18n")
			@Override
			public void onResponse(Call<Car> call, Response<Car> response) {
				if (response.body() != null) {
					Car car = response.body();
					Glide.with(CarDetailsActivity.this).load(car.getImage()).into(image);
					category.setText(car.getCategory().getName());
					daily_fine.setText("R$ " + car.getFine_amount());
					daily_price.setText("R$ " + car.getDaily_rate());
					model.setText(car.getName());
				}
			}

			@Override
			public void onFailure(Call<Car> call, Throwable t) {
				Snackbar
					.make(findViewById(android.R.id.content), "Não foi possível conectar ao servidor", Snackbar.LENGTH_LONG)
					.setBackgroundTint(
						getResources().getColor(R.color.red_500, getTheme()))
					.show();
			}
		});

		rent.setOnClickListener(view -> {
			Calendar newDate = Calendar.getInstance();
			newDate.set(
				newDate.get(Calendar.YEAR),
				newDate.get(Calendar.MONTH),
				newDate.get(Calendar.DAY_OF_MONTH) + 2,
				newDate.get(Calendar.HOUR_OF_DAY),
				newDate.get(Calendar.MINUTE),
				newDate.get(Calendar.SECOND)
			);

			Log.d("dates", newDate.toInstant().toString());

			(rentService.rentCar("Bearer " + userSession.getToken(), new RentCar(carId, newDate.toInstant().toString())))
				.enqueue(new Callback<RentCarRet>() {
					@Override
					public void onResponse(Call<RentCarRet> call, Response<RentCarRet> response) {
						Log.d("errors", response.message());
						if (response.code() == 400) {
							Snackbar
								.make(findViewById(android.R.id.content), "Devolva seu carro alugado primeiro.", Snackbar.LENGTH_LONG)
								.setBackgroundTint(
									getResources().getColor(R.color.red_500, getTheme()))
								.show();
						} else if (response.code() == 201) {
							Intent intent = new Intent(CarDetailsActivity.this, MyLoanedCarActivity.class);

							startActivity(intent);
						}
					}

					@Override
					public void onFailure(Call<RentCarRet> call, Throwable t) {
						Log.d("errors", t.getMessage());

						Snackbar
							.make(findViewById(android.R.id.content), "Não foi possível garantir seu aluguel", Snackbar.LENGTH_LONG)
							.setBackgroundTint(
								getResources().getColor(R.color.red_500, getTheme()))
							.show();
					}
				});
			});
	}
}