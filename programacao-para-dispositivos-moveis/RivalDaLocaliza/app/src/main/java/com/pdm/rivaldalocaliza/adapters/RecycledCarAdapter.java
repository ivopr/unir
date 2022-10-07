package com.pdm.rivaldalocaliza.adapters;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;
import com.pdm.rivaldalocaliza.activities.CarDetailsActivity;
import com.pdm.rivaldalocaliza.models.Car;
import com.pdm.rivaldalocaliza.R;

import java.util.List;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class RecycledCarAdapter extends RecyclerView.Adapter<RecycledCarAdapter.ViewHolder> {
	List<Car> list;

	@NonNull
	@Override
	public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
		View v = LayoutInflater
			.from(parent.getContext())
			.inflate(R.layout.available_car_recycled_item, parent, false);

		return new ViewHolder(v);
	}

	@SuppressLint("SetTextI18n")
	@Override
	public void onBindViewHolder(@NonNull RecycledCarAdapter.ViewHolder holder, int position) {
		Car item = list.get(position);

		holder.itemView.setOnClickListener(view -> {
			Intent intent = new Intent(holder.itemView.getContext(), CarDetailsActivity.class);

			intent.putExtra("carId", "" + item.getId());

			holder.itemView.getContext().startActivity(intent);
		});

		Glide.with(holder.itemView.getContext()).load(item.getImage()).into(holder.image);
		holder.category.setText(item.getCategory().getName());
		holder.description.setText(item.getDescription());
		holder.model.setText(item.getName());
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	@SuppressLint("NotifyDataSetChanged")
	public void update(List<Car> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView category, description, model;
		ImageView image;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			image = itemView.findViewById(R.id.recycled_car_image);
			category = itemView.findViewById(R.id.recycled_car_category);
			description = itemView.findViewById(R.id.recycled_car_description);
			model = itemView.findViewById(R.id.recycled_car_model);
		}
	}
}