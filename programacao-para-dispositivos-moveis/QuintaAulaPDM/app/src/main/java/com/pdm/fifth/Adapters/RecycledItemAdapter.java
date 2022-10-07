package com.pdm.fifth.Adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.pdm.fifth.Models.RecycledItem;
import com.pdm.fifth.Models.Repo;
import com.pdm.fifth.R;

import java.util.List;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class RecycledItemAdapter extends RecyclerView.Adapter<RecycledItemAdapter.ViewHolder> {
	List<Repo> list;

	@NonNull
	@Override
	public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
		View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.recycled_item, parent, false);

		return new ViewHolder(v);
	}

	@Override
	public void onBindViewHolder(@NonNull RecycledItemAdapter.ViewHolder holder, int position) {
		Repo item = list.get(position);

		holder.name.setText(item.getName());
	}

	@Override
	public int getItemCount() {
		return list.size();
	}

	public void update(List<Repo> list) {
		this.list = list;
		this.notifyDataSetChanged();
	}

	static class ViewHolder extends RecyclerView.ViewHolder {
		TextView name;

		public ViewHolder(@NonNull View itemView) {
			super(itemView);
			name = itemView.findViewById(R.id.recycled_item_name);
		}
	}
}
