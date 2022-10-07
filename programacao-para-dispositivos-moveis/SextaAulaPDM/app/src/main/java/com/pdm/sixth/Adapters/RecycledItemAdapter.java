package com.pdm.sixth.Adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.pdm.sixth.Models.RecycledItem;
import com.pdm.sixth.R;

import java.util.List;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class RecycledItemAdapter extends RecyclerView.Adapter<RecycledItemAdapter.ViewHolder> {
	List<RecycledItem> list;

	@NonNull
	@Override
	public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
		View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.recycled_item, parent, false);

		return new ViewHolder(v);
	}

	@SuppressLint("SetTextI18n")
	@Override
	public void onBindViewHolder(@NonNull RecycledItemAdapter.ViewHolder holder, int position) {
		RecycledItem item = list.get(position);

		holder.name.setText(item.getName());
		holder.description.setText(item.getDescription());
		holder.price.setText("R$ " + item.getPrice());
		holder.image.setImageResource(item.getImage());
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	public void update(List<RecycledItem> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView name, description, price;
		ImageView image;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			name = itemView.findViewById(R.id.recycled_name);
			description = itemView.findViewById(R.id.recycled_description);
			image = itemView.findViewById(R.id.recycled_image);
			price = itemView.findViewById(R.id.recycled_price);
		}
	}
}
