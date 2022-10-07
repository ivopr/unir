package com.pdm.amarelo.activities.ui.home;

import android.app.AlertDialog;
import android.os.Bundle;
import android.text.InputType;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.datepicker.CalendarConstraints;
import com.google.android.material.datepicker.DateValidatorPointForward;
import com.google.android.material.datepicker.MaterialDatePicker;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.pdm.amarelo.R;
import com.pdm.amarelo.adapters.BookingsAdapter;
import com.pdm.amarelo.databinding.FragmentHomeBinding;
import com.pdm.amarelo.room.AppDb;
import com.pdm.amarelo.room.Database;
import com.pdm.amarelo.room.daos.BookingDAO;
import com.pdm.amarelo.room.entities.Booking;
import com.pdm.amarelo.singletons.BookingsRecyclerSingleton;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.concurrent.atomic.AtomicLong;

public class HomeFragment extends Fragment {
	private HomeViewModel homeViewModel;
	private FragmentHomeBinding binding;
	private AppDb database;

	public View onCreateView(
		@NonNull LayoutInflater inflater,
		ViewGroup container,
		Bundle savedInstanceState
	) {
		homeViewModel =
			new ViewModelProvider(this).get(HomeViewModel.class);

		binding = FragmentHomeBinding.inflate(
			inflater,
			container,
			false
		);

		View root = binding.getRoot();

		database = Database.getDatabase(root.getContext());
		BookingDAO bookingsDAO = database.getBookingDAO();

		BookingsAdapter bAdapter =
			BookingsRecyclerSingleton.getAdapter(bookingsDAO.getBookings());

		final RecyclerView bookingsR = binding.bookingsRecycler;

		bookingsR.setHasFixedSize(true);
		bookingsR.setLayoutManager(new LinearLayoutManager(root.getContext()));
		bookingsR.setAdapter(bAdapter);

		FloatingActionButton fButton = root.findViewById(R.id.add_booking);

		fButton.setOnClickListener(view -> {
			AlertDialog alertDialog = new AlertDialog.Builder(root.getContext()).create();
			alertDialog.setTitle("Adicionar Agendamento");

			final EditText adults = new EditText(root.getContext());
			adults.setInputType(InputType.TYPE_CLASS_TEXT);
			adults.setHint("Número de Adultos");
			final EditText children = new EditText(root.getContext());
			children.setInputType(InputType.TYPE_CLASS_TEXT);
			children.setHint("Número de Crianças");
			final EditText babies = new EditText(root.getContext());
			babies.setInputType(InputType.TYPE_CLASS_TEXT);
			babies.setHint("Número de Bebês");

			AtomicLong departureDate = new AtomicLong();
			AtomicLong returnDate = new AtomicLong();

			final Button departureButton = new Button(root.getContext());
			departureButton.setText("Data de partida");
			departureButton.setOnClickListener(v -> {
				CalendarConstraints calendarConstraints = new CalendarConstraints
					.Builder()
					.setValidator(
						DateValidatorPointForward.now()
					).build();
				MaterialDatePicker<Long> datepicker = MaterialDatePicker
					.Builder
					.datePicker()
					.setCalendarConstraints(calendarConstraints)
					.setTitleText("Selecione a data de partida")
					.build();

				datepicker.addOnPositiveButtonClickListener(selection -> {
					SimpleDateFormat date = new SimpleDateFormat("dd/MM/yyyy", Locale.getDefault());
					departureDate.set(selection + (24 * 60 * 60 * 1000L));

					departureButton.setText(date.format(new Date(departureDate.get())));
				});
				datepicker.show(requireActivity().getSupportFragmentManager(), "departure");
			});

			final Button returnButton = new Button(root.getContext());
			returnButton.setText("Data de retorno");
			returnButton.setOnClickListener(v -> {
				CalendarConstraints calendarConstraints = new CalendarConstraints
					.Builder()
					.setValidator(
						DateValidatorPointForward.from(departureDate.get())
					).build();
				MaterialDatePicker<Long> datepicker = MaterialDatePicker
					.Builder
					.datePicker()
					.setCalendarConstraints(calendarConstraints)
					.setTitleText("Selecione a data de partida")
					.build();

				datepicker.addOnPositiveButtonClickListener(selection -> {
					SimpleDateFormat date = new SimpleDateFormat("dd/MM/yyyy", Locale.getDefault());
					returnDate.set(selection + (24 * 60 * 60 * 1000L));

					returnButton.setText(date.format(new Date(returnDate.get())));
				});
				datepicker.show(requireActivity().getSupportFragmentManager(), "departure");
			});

			LinearLayout layoutName = new LinearLayout(root.getContext());
			layoutName.setOrientation(LinearLayout.VERTICAL);
			layoutName.addView(adults);
			layoutName.addView(children);
			layoutName.addView(babies);
			layoutName.addView(departureButton);
			layoutName.addView(returnButton);
			alertDialog.setView(layoutName);

			alertDialog.setButton(AlertDialog.BUTTON_POSITIVE, "Cadastrar", (dialog, whichButton) -> {
				try {
					// create new booking
					Booking newBooking = new Booking();
					newBooking.setAdults(Integer.parseInt(adults.getText().toString()));
					newBooking.setChildren(Integer.parseInt(children.getText().toString()));
					newBooking.setBabies(Integer.parseInt(babies.getText().toString()));
					newBooking.setArrival(returnDate.get());
					newBooking.setDeparture(departureDate.get());

					// insert and update recycler
					bookingsDAO.insert(newBooking);
					bAdapter.update(bookingsDAO.getBookings());
				} catch(Exception ignored) {
					AlertDialog.Builder errorDialog =
						new AlertDialog.Builder(root.getContext());

					errorDialog.setTitle("Falha.");
					errorDialog.setMessage("Não foi possível adicionar esse agendamento.");
					errorDialog.setPositiveButton("OK", (dialog1, whichButton1) -> {
						alertDialog.dismiss();
					});
					errorDialog.setNegativeButton("Alterar", (dialog1, whichButton1) -> {
						alertDialog.show();
					});
					errorDialog.show();
				}
			});

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