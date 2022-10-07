package com.pdm.amarelo.activities.ui.dashboard;

import android.app.AlertDialog;
import android.os.Bundle;
import android.text.InputType;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Spinner;
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
import com.pdm.amarelo.adapters.BookingsAdapter;
import com.pdm.amarelo.adapters.TicketsAdapter;
import com.pdm.amarelo.databinding.FragmentDashboardBinding;
import com.pdm.amarelo.room.AppDb;
import com.pdm.amarelo.room.Database;
import com.pdm.amarelo.room.daos.TicketDAO;
import com.pdm.amarelo.room.entities.Booking;
import com.pdm.amarelo.room.entities.City;
import com.pdm.amarelo.room.entities.Ticket;
import com.pdm.amarelo.room.relations.BookingAndTickets;
import com.pdm.amarelo.singletons.BookingsRecyclerSingleton;

import java.util.ArrayList;
import java.util.List;

public class DashboardFragment extends Fragment {
	private DashboardViewModel dashboardViewModel;
	private FragmentDashboardBinding binding;
	private AppDb database;

	public View onCreateView(
		@NonNull LayoutInflater inflater,
	 	ViewGroup container,
		Bundle savedInstanceState
	) {
		dashboardViewModel = new ViewModelProvider(this)
													.get(DashboardViewModel.class);

		binding = FragmentDashboardBinding.inflate(
			inflater,
			container,
			false
		);

		View root = binding.getRoot();
		database = Database.getDatabase(root.getContext());
		TicketDAO ticketDAO = database.getTicketDAO();
		Ticket newTicket = new Ticket();
		TicketsAdapter tAdapter = new TicketsAdapter(ticketDAO.getTickets());

		final RecyclerView ticketsR = binding.recyclerTicket;

		ticketsR.setHasFixedSize(true);
		ticketsR.setLayoutManager(new LinearLayoutManager(root.getContext()));
		ticketsR.setAdapter(tAdapter);

		FloatingActionButton fButton = root.findViewById(R.id.add_ticket);

		fButton.setOnClickListener(view -> {
			AlertDialog alertDialog = new AlertDialog.Builder(root.getContext()).create();
			alertDialog.setTitle("Adicionar Passagem");
			List<City> cities = database.getCityDAO().getCities();
			List<BookingAndTickets> bookings = database.getBookingDAO().getBookings();

			Spinner dropdownBookings = new Spinner(root.getContext());
			dropdownBookings.setLayoutMode(Spinner.MODE_DROPDOWN);
			List<String> bookingItems = new ArrayList<>();
			for (BookingAndTickets i : bookings) {
				bookingItems.add("" + i.booking.getId());
			}
			ArrayAdapter<String> adapter =
				new ArrayAdapter(
					root.getContext(),
					android.R.layout.simple_spinner_dropdown_item,
					bookingItems
				);
			dropdownBookings.setAdapter(adapter);
			dropdownBookings.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
				@Override
				public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
					Long bookingId =
						Long.parseLong(adapterView.getItemAtPosition(i).toString());

					newTicket.setBookingId(bookingId);
				}

				@Override
				public void onNothingSelected(AdapterView<?> adapterView) {}
			});

			Spinner dropdownOrigin = new Spinner(root.getContext());
			dropdownOrigin.setLayoutMode(Spinner.MODE_DROPDOWN);
			List<String> cityItems = new ArrayList<>();
			for (City i : cities) {
				cityItems.add(i.getName());
			}
			ArrayAdapter<String> cityAdapter =
				new ArrayAdapter(
					root.getContext(),
					android.R.layout.simple_spinner_dropdown_item,
					cityItems
				);
			dropdownOrigin.setAdapter(cityAdapter);
			dropdownOrigin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
				@Override
				public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
					City selectedCity =
						database
							.getCityDAO()
							.getCityByName(adapterView.getItemAtPosition(i).toString());

					newTicket.setOriginId(selectedCity.getId());
				}

				@Override
				public void onNothingSelected(AdapterView<?> adapterView) {}
			});

			Spinner dropdownDestination = new Spinner(root.getContext());
			dropdownDestination.setLayoutMode(Spinner.MODE_DROPDOWN);
			dropdownDestination.setAdapter(cityAdapter);
			dropdownDestination.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
				@Override
				public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
					City selectedCity =
						database
							.getCityDAO()
							.getCityByName(adapterView.getItemAtPosition(i).toString());

					newTicket.setDestinationId(selectedCity.getId());
				}

				@Override
				public void onNothingSelected(AdapterView<?> adapterView) {}
			});

			final EditText price = new EditText(root.getContext());
			price.setInputType(InputType.TYPE_CLASS_TEXT);
			price.setHint("Preço");

			LinearLayout layoutName = new LinearLayout(root.getContext());
			layoutName.setOrientation(LinearLayout.VERTICAL);
			layoutName.addView(dropdownBookings);
			layoutName.addView(dropdownOrigin);
			layoutName.addView(dropdownDestination);
			layoutName.addView(price);
			alertDialog.setView(layoutName);

			alertDialog.setButton(
				AlertDialog.BUTTON_POSITIVE,
				"Cadastrar",
				(dialog, whichButton) -> {
					try {
						newTicket.setPrice(
							Double.parseDouble(price.getText().toString())
						);

						ticketDAO.insert(newTicket);
						tAdapter.update(ticketDAO.getTickets());
						BookingsRecyclerSingleton
							.getAdapter(database.getBookingDAO().getBookings())
							.update(database.getBookingDAO().getBookings());
					} catch (Exception ignored) {

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