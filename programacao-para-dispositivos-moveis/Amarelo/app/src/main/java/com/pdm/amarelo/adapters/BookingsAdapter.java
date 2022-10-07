package com.pdm.amarelo.adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.pdm.amarelo.R;
import com.pdm.amarelo.room.relations.BookingAndTickets;
import com.pdm.amarelo.room.relations.TicketAndCities;

import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Locale;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class BookingsAdapter extends RecyclerView.Adapter<BookingsAdapter.ViewHolder> {
	List<BookingAndTickets> list;

	@NonNull
	@Override
	public ViewHolder onCreateViewHolder(
		@NonNull ViewGroup parent,
		int viewType
	) {
		View v = LayoutInflater
			.from(parent.getContext())
			.inflate(R.layout.recycled_booking, parent, false);

		return new ViewHolder(v);
	}

	@SuppressLint("SetTextI18n")
	@Override
	public void onBindViewHolder(
		@NonNull BookingsAdapter.ViewHolder holder,
		int position
	) {
		SimpleDateFormat date =
			new SimpleDateFormat("dd/MM/yyyy", Locale.getDefault());
		BookingAndTickets item = list.get(position);
		Double totalPrice = 0.0;

		if (item.tickets.size() != 0) {
			for (TicketAndCities ticket : item.tickets) {
				totalPrice += ticket.ticket.getPrice();
			}
		}

		holder.name.setText("Booking " + item.booking.getId());
		holder.passengersCount.setText(
			item.booking.getAdults() +
			"/" + item.booking.getChildren() +
			"/" + item.booking.getBabies()
		);
		holder.departureDate.setText(date.format(item.booking.getDeparture()));
		holder.returnDate.setText(date.format(item.booking.getArrival()));
		if (item.tickets.size() != 0) {
			holder.price.setText("R$ " + totalPrice);
		} else {
			holder.price.setText("R$ 0,00");
		}
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	@SuppressLint("NotifyDataSetChanged")
	public void update(List<BookingAndTickets> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView name, passengersCount, departureDate, returnDate, price;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			name = itemView.findViewById(R.id.booking_name);
			passengersCount = itemView.findViewById(R.id.passengers);
			departureDate = itemView.findViewById(R.id.departure_date);
			returnDate = itemView.findViewById(R.id.return_date);
			price = itemView.findViewById(R.id.price);
		}
	}
}
