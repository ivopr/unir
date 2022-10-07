package com.pdm.fourth;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.TextView;

import com.pdm.fourth.Model.Pizza;

public class SelectPizza extends AppCompatActivity {
	private int total = 0;
	private final int VAL1 = 100;
	private final int VAL2 = 200;
	private final int VAL3 = 300;
	private final int VAL4 = 400;
	private final int VAL5 = 500;

	@SuppressLint("SetTextI18n")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_select_pizza);

		Pizza p = new Pizza("1", "1", 1.0);

		CheckBox pizza1 = findViewById(R.id.checkbox_pizza1);
		CheckBox pizza2 = findViewById(R.id.checkbox_pizza2);
		CheckBox pizza3 = findViewById(R.id.checkbox_pizza3);
		CheckBox pizza4 = findViewById(R.id.checkbox_pizza4);
		CheckBox pizza5 = findViewById(R.id.checkbox_pizza5);

		TextView totalValue = findViewById(R.id.total);

		totalValue.setText("R$ " + total);

		pizza1.setOnClickListener(event -> {
			if (pizza1.isChecked()) {
				total += VAL1;
			} else {
				total -= VAL1;
			}
			totalValue.setText("R$ " + total);
		});

		pizza2.setOnClickListener(event -> {
			if (pizza2.isChecked()) {
				total += VAL2;
			} else {
				total -= VAL2;
			}
			totalValue.setText("R$ " + total);
		});

		pizza3.setOnClickListener(event -> {
			if (pizza3.isChecked()) {
				total += VAL3;
			} else {
				total -= VAL3;
			}
			totalValue.setText("R$ " + total);
		});

		pizza4.setOnClickListener(event -> {
			if (pizza4.isChecked()) {
				total += VAL4;
			} else {
				total -= VAL4;
			}
			totalValue.setText("R$ " + total);
		});

		pizza5.setOnClickListener(event -> {
			if (pizza5.isChecked()) {
				total += VAL5;
			} else {
				total -= VAL5;
			}
			totalValue.setText("R$ " + total);
		});

		Button cleanSelection = findViewById(R.id.clean_selection);

		cleanSelection.setOnClickListener(event -> {
			pizza1.setChecked(false);
			pizza2.setChecked(false);
			pizza3.setChecked(false);
			pizza4.setChecked(false);
			pizza5.setChecked(false);

			totalValue.setText("R$ 0,00");
		});

		Button placeOrder = findViewById(R.id.place_order);

		placeOrder.setOnClickListener(event -> {
			Intent intent =  new Intent(this, PlaceOrder.class);

			intent.putExtra("total", "R$ " + total);

			startActivity(intent);
		});
	}
}