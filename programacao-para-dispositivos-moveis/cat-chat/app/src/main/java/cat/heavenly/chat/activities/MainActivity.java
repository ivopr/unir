package cat.heavenly.chat.activities;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.NavigationUI;

import cat.heavenly.chat.R;
import cat.heavenly.chat.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
	private ActivityMainBinding binding;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		binding = ActivityMainBinding.inflate(getLayoutInflater());
		setContentView(binding.getRoot());

		NavController navController = Navigation
			.findNavController(this, R.id.nav_host_fragment_activity_main);
		NavigationUI
			.setupWithNavController(binding.navView, navController);
	}
}