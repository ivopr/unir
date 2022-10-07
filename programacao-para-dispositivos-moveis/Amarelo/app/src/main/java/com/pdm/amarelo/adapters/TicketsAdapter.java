package com.pdm.amarelo.adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.pdm.amarelo.R;
import com.pdm.amarelo.room.relations.TicketAndCities;

import java.util.List;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class TicketsAdapter extends RecyclerView.Adapter<TicketsAdapter.ViewHolder>{
	private List<TicketAndCities> list;

	@NonNull
	@Override
	public TicketsAdapter.ViewHolder onCreateViewHolder(
		@NonNull ViewGroup parent,
		int viewType
	) {
		View v = LayoutInflater
			.from(parent.getContext())
			.inflate(R.layout.recycled_ticket, parent, false);

		return new TicketsAdapter.ViewHolder(v);
	}

	@SuppressLint("SetTextI18n")
	@Override
	public void onBindViewHolder(
		@NonNull TicketsAdapter.ViewHolder holder,
		int position
	) {
		TicketAndCities item = list.get(position);

		holder.destination.setText(
			item.destination.getName() + " - " + item.destination.getAirport()
		);
		holder.origin.setText(
			item.origin.getName() + " - " + item.origin.getAirport()
		);
		holder.price.setText("R$ " + item.ticket.getPrice());
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	@SuppressLint("NotifyDataSetChanged")
	public void update(List<TicketAndCities> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView origin, destination, price;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			origin = itemView.findViewById(R.id.ticket_origin);
			destination = itemView.findViewById(R.id.ticket_destination);
			price = itemView.findViewById(R.id.ticket_price);
		}
	}
}
