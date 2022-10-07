package com.pdm.fourth;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        EditText phone = findViewById(R.id.phone_number_field);
        EditText password = findViewById(R.id.password_field);
        Button login = findViewById(R.id.login);

        login.setOnClickListener(event -> {
            Intent intent = new Intent(this, SelectPizza2.class);

            phone.setText("");
            password.setText("");

            startActivity(intent);
        });
    }
}