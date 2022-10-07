package com.pdm.one;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		/* Recupera Botão da Tela */
		Button btn = findViewById(R.id.button_one);

		/* Ouve o clique no botão e exibe um Toast se clicado */
		btn.setOnClickListener(v ->
			Toast.makeText(getBaseContext(), R.string.app_name, Toast.LENGTH_LONG).show()
		);
	}
}