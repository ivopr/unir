package com.pdm.amarelo.adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.pdm.amarelo.R;
import com.pdm.amarelo.room.entities.City;

import java.util.List;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class CitiesAdapter extends RecyclerView.Adapter<CitiesAdapter.ViewHolder> {
	List<City> list;

	@NonNull
	@Override
	public CitiesAdapter.ViewHolder onCreateViewHolder(
		@NonNull ViewGroup parent,
		int viewType
	) {
		View v = LayoutInflater
			.from(parent.getContext())
			.inflate(R.layout.recycled_city, parent, false);

		return new CitiesAdapter.ViewHolder(v);
	}

	@SuppressLint("SetTextI18n")
	@Override
	public void onBindViewHolder(
		@NonNull CitiesAdapter.ViewHolder holder,
		int position
	) {
		City item = list.get(position);

		holder.cityName.setText(item.getName() + " - " + item.getAirport());
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	@SuppressLint("NotifyDataSetChanged")
	public void update(List<City> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView cityName;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			cityName = itemView.findViewById(R.id.city_name);
		}
	}
}
