package com.pdm.rivaldalocaliza.activities;

import com.pdm.rivaldalocaliza.R;
import com.pdm.rivaldalocaliza.adapters.RecycledCarAdapter;
import com.pdm.rivaldalocaliza.api.API;
import com.pdm.rivaldalocaliza.api.services.RentService;
import com.pdm.rivaldalocaliza.models.Car;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class AvailableCarsActivity extends AppCompatActivity {
	private List<Car> list = new ArrayList<>();
	private RecycledCarAdapter rca = new RecycledCarAdapter(list);

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_available_cars);

		API api = new API();
		RentService rentService = api.getRentService();

		(rentService.listAvailableCars()).enqueue(new Callback<List<Car>>() {
			@Override
			public void onResponse(Call<List<Car>> call, Response<List<Car>> response) {
				assert response.body() != null;
				rca.update(response.body());
			}

			@Override
			public void onFailure(Call<List<Car>> call, Throwable t) {
				Log.d("failReq", t.getMessage());
				Toast.makeText(AvailableCarsActivity.this, "Não foi possível recuperar os carros disponíveis", Toast.LENGTH_LONG).show();
			}
		});

		RecyclerView availableCarsRecycler = findViewById(R.id.available_cars_recycler);
		availableCarsRecycler.setAdapter(rca);
		availableCarsRecycler.setLayoutManager(new GridLayoutManager(this, 2));
	}
}