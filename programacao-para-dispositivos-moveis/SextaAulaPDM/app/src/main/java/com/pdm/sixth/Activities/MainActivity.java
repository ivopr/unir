package com.pdm.sixth.Activities;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import com.pdm.sixth.R;

public class MainActivity extends AppCompatActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		Button recyclerButton = findViewById(R.id.button_recycler_view);
		recyclerButton.setOnClickListener(event -> {
			Intent intent = new Intent(this, RecyclerActivity.class);

			startActivity(intent);
		});
	}
}