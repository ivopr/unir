package com.pdm.amarelo.activities.ui.notifications;

import android.app.AlertDialog;
import android.os.Bundle;
import android.text.InputType;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.pdm.amarelo.R;
import com.pdm.amarelo.adapters.CitiesAdapter;
import com.pdm.amarelo.databinding.FragmentNotificationsBinding;
import com.pdm.amarelo.room.AppDb;
import com.pdm.amarelo.room.Database;
import com.pdm.amarelo.room.daos.CityDAO;
import com.pdm.amarelo.room.entities.Booking;
import com.pdm.amarelo.room.entities.City;

public class NotificationsFragment extends Fragment {
	private NotificationsViewModel notificationsViewModel;
	private FragmentNotificationsBinding binding;
	private AppDb database;

	public View onCreateView(
		@NonNull LayoutInflater inflater,
		ViewGroup container,
		Bundle savedInstanceState
	) {
		notificationsViewModel =
			new ViewModelProvider(this).get(NotificationsViewModel.class);

		binding = FragmentNotificationsBinding.inflate(
			inflater,
			container,
			false
		);

		View root = binding.getRoot();

		database = Database.getDatabase(root.getContext());
		CityDAO cityDAO = database.getCityDAO();

		CitiesAdapter cAdapter = new CitiesAdapter(cityDAO.getCities());

		final RecyclerView citiesR = binding.recyclerCities;

		citiesR.setHasFixedSize(true);
		citiesR.setLayoutManager(new LinearLayoutManager(root.getContext()));
		citiesR.setAdapter(cAdapter);

		FloatingActionButton fButton = root.findViewById(R.id.add_city);

		fButton.setOnClickListener(view -> {
			AlertDialog alertDialog = new AlertDialog.Builder(root.getContext()).create();
			alertDialog.setTitle("Adicionar Cidade");

			final EditText city = new EditText(root.getContext());
			city.setInputType(InputType.TYPE_CLASS_TEXT);
			city.setHint("Nome");
			final EditText airport = new EditText(root.getContext());
			airport.setInputType(InputType.TYPE_CLASS_TEXT);
			airport.setHint("Aeroporto");

			LinearLayout layoutName = new LinearLayout(root.getContext());
			layoutName.setOrientation(LinearLayout.VERTICAL);
			layoutName.addView(city);
			layoutName.addView(airport);
			alertDialog.setView(layoutName);

			alertDialog.setButton(
				AlertDialog.BUTTON_POSITIVE,
				"Cadastrar",
				(dialog, whichButton) -> {
					try {
						City newCity = new City();
						newCity.setAirport(airport.getText().toString());
						newCity.setName(city.getText().toString());

						cityDAO.insert(newCity);
						cAdapter.update(cityDAO.getCities());
					} catch (Exception ignored) {
						AlertDialog.Builder errorDialog =
							new AlertDialog.Builder(root.getContext());

						errorDialog.setTitle("Falha.");
						errorDialog.setMessage("Não foi possível adicionar essa cidade.");
						errorDialog.setPositiveButton("OK", (dialog1, whichButton1) -> {
							alertDialog.dismiss();
						});
						errorDialog.setNegativeButton("Alterar", (dialog1, whichButton1) -> {
							alertDialog.show();
						});
						errorDialog.show();
					}
				}
			);

			alertDialog.show();
		});

		return root;
	}

	@Override
	public void onDestroyView() {
		super.onDestroyView();
		binding = null;
	}
}