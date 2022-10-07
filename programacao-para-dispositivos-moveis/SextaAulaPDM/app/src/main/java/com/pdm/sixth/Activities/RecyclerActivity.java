package com.pdm.sixth.Activities;

import com.pdm.sixth.Adapters.RecycledItemAdapter;
import com.pdm.sixth.Models.RecycledItem;
import com.pdm.sixth.R;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class RecyclerActivity extends AppCompatActivity {
	List<RecycledItem> list = new ArrayList<>();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_recycler);

		try {
			InputStream arquivo = this.getResources().openRawResource(R.raw.pratos);
			InputStreamReader leitor = new InputStreamReader(arquivo);
			BufferedReader leitorDeBuffer = new BufferedReader(leitor);

			String[] item;
			String linha;

			while ((linha = leitorDeBuffer.readLine()) != null){
				item = linha.split(",");

				list.add(new RecycledItem(item[0], item[1], getResources().getIdentifier(item[3], "drawable", getPackageName()), Double.parseDouble(item[2])));
			}
		}catch(IOException e){
			Toast.makeText(this,
				"Erro ao ler arquivo (id " + R.raw.pratos + ")",
				Toast.LENGTH_SHORT).show();
		}

		RecycledItemAdapter ria = new RecycledItemAdapter(list);
		RecyclerView rv = findViewById(R.id.recycler_view);
		rv.setAdapter(ria);
		rv.setLayoutManager(new LinearLayoutManager(this));
	}
}