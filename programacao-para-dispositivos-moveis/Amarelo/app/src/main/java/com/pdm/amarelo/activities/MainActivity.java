package com.pdm.amarelo.activities;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.pdm.amarelo.R;
import com.pdm.amarelo.room.AppDb;
import com.pdm.amarelo.room.Database;
import com.pdm.amarelo.room.entities.Ticket;

public class MainActivity extends AppCompatActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		AppDb database = Database.getDatabase(this);
	}
}