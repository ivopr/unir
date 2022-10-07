package com.pdm.todo.adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.ToggleButton;

import androidx.recyclerview.widget.RecyclerView;

import com.pdm.todo.room.AppDb;
import com.pdm.todo.room.daos.TodoDAO;
import com.pdm.todo.room.entities.Todo;

import java.util.List;

import lombok.AllArgsConstructor;
import lombok.NonNull;

import com.pdm.todo.R;

@AllArgsConstructor
public class TodoAdapter extends RecyclerView.Adapter<TodoAdapter.ViewHolder> {
    List<Todo> todos;
    AppDb database;

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater
                .from(parent.getContext())
                .inflate(R.layout.fragment_todo, parent, false);

        return new ViewHolder(v);
    }

    @SuppressLint("SetTextI18n")
    @Override
    public void onBindViewHolder(@NonNull TodoAdapter.ViewHolder holder, int position) {
        Todo item = todos.get(position);
        Integer humanPosition = position + 1;

        holder.number.setText("" + humanPosition);
        holder.title.setText(item.getTitle());

        holder.complete.setEnabled(!item.getIsCompleted());
        holder.complete.setChecked(item.getIsCompleted());

        holder.complete.setOnClickListener(view -> {
            TodoDAO todoDAO = database.getTodoDAO();
            item.setIsCompleted(true);

            todoDAO.update(item);

            this.notifyItemChanged(position);
        });
    }

    @Override
    public int getItemCount() {
        return todos.size();
    }

    @SuppressLint("NotifyDataSetChanged")
    public void update(List<Todo> list) {
        this.todos = list;
        this.notifyDataSetChanged();
    }

    static class ViewHolder extends RecyclerView.ViewHolder {
        TextView number, title;
        ToggleButton complete;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            number = itemView.findViewById(R.id.item_number);
            title = itemView.findViewById(R.id.todo_title);
            complete = itemView.findViewById(R.id.complete);
        }
    }
}
