package com.pdm.third;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.Switch;
import android.widget.Toast;

public class PlaceOrder extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_place_order);

        RadioButton money = findViewById(R.id.radio_money);
        RadioButton card = findViewById(R.id.radio_card);
        RadioButton pix = findViewById(R.id.radio_pix);

        money.setOnClickListener(event -> {
            if (money.isChecked()) {
                card.setChecked(false);
                pix.setChecked(false);
            }
        });

        card.setOnClickListener(event -> {
            if (card.isChecked()) {
                money.setChecked(false);
                pix.setChecked(false);
            }
        });

        pix.setOnClickListener(event -> {
            if (pix.isChecked()) {
                money.setChecked(false);
                card.setChecked(false);
            }
        });

        @SuppressLint("UseSwitchCompatOrMaterialCode")
        Switch delivery = findViewById(R.id.switch_delivery);

        Button confirm = findViewById(R.id.confirm);

        confirm.setOnClickListener(event -> {
            if (delivery.isChecked()) {
                Toast.makeText(this, "Seu pedido será entregue em ...", Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(this, "Venha buscar seu pedido em ...", Toast.LENGTH_SHORT).show();
            }
        });

        Button returnToSelection = findViewById(R.id.return_to_selection);

        returnToSelection.setOnClickListener(event -> {
            finish();
        });
    }
}