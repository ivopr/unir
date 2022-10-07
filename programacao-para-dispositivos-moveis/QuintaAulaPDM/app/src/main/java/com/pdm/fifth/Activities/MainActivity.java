package com.pdm.fifth.Activities;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.Toast;

import com.pdm.fifth.Adapters.RecycledItemAdapter;
import com.pdm.fifth.Models.RecycledItem;
import com.pdm.fifth.Models.Repo;
import com.pdm.fifth.R;
import com.pdm.fifth.Retrofit.API;
import com.pdm.fifth.Retrofit.Services.GithubService;

import org.json.JSONArray;

import java.util.ArrayList;
import java.util.List;

import okhttp3.ResponseBody;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class MainActivity extends AppCompatActivity {
	private List<Repo> list = new ArrayList<>();
	private RecycledItemAdapter ria;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		ria = new RecycledItemAdapter(list);

		API api = new API();
		GithubService service = api.getGservice();

		(service.listRepos("ivopr")).enqueue(new Callback<List<Repo>>() {
			@Override
			public void onResponse(Call<List<Repo>> call, Response<List<Repo>> response) {
				assert response.body() != null;
				ria.update(response.body());
				Log.d("retD", "entrou e sucesso");
				Toast.makeText(MainActivity.this, "foi", Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onFailure(Call<List<Repo>> call, Throwable t) {
				Toast.makeText(MainActivity.this, "falhou", Toast.LENGTH_SHORT).show();
				Log.d("retD", "entrou e falha");
			}
		});

		RecyclerView rv = findViewById(R.id.recycler_view);

		rv.setAdapter(ria);
		rv.setLayoutManager(new LinearLayoutManager(this));

	}
}