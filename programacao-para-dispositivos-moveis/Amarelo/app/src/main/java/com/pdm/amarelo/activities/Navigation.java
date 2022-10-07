package com.pdm.amarelo.activities;

import android.os.Bundle;

import com.google.android.material.bottomnavigation.BottomNavigationView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.NavController;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import com.pdm.amarelo.databinding.ActivityNavigationBinding;
import com.pdm.amarelo.R;

public class Navigation extends AppCompatActivity {

	private ActivityNavigationBinding binding;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		binding = ActivityNavigationBinding.inflate(getLayoutInflater());
		setContentView(binding.getRoot());

		BottomNavigationView navView = findViewById(R.id.nav_view);
		// Passing each menu ID as a set of Ids because each
		// menu should be considered as top level destinations.
		AppBarConfiguration appBarConfiguration = new AppBarConfiguration.Builder(
			R.id.navigation_home,
			R.id.navigation_dashboard,
			R.id.navigation_notifications
		)
			.build();
		NavController navController = androidx.navigation.Navigation.findNavController(this, R.id.nav_host_fragment_activity_navigation);
		NavigationUI.setupActionBarWithNavController(this, navController, appBarConfiguration);
		NavigationUI.setupWithNavController(binding.navView, navController);
	}

}