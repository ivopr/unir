package com.pdm.todo.activities;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import com.pdm.todo.R;
import com.pdm.todo.adapters.TodoAdapter;
import com.pdm.todo.room.AppDb;
import com.pdm.todo.room.Database;
import com.pdm.todo.room.daos.TodoDAO;
import com.pdm.todo.room.entities.Todo;

import java.util.List;

public class MainActivity extends AppCompatActivity {
    private AppDb database;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        database = Database.getDatabase(this);
        TodoDAO todoDAO = database.getTodoDAO();

        Button addTodo = findViewById(R.id.add_todo_button);
        TextView newTodoText = findViewById(R.id.new_todo_text);
        RecyclerView todoList = findViewById(R.id.todos_list);

        TodoAdapter tAdapter = new TodoAdapter(todoDAO.getTodos(), database);
        todoList.setAdapter(tAdapter);
        todoList.setLayoutManager(new LinearLayoutManager(this));

        addTodo.setOnClickListener(view -> {
            if (!newTodoText.getText().toString().isEmpty()) {
                Todo newTodo = new Todo();
                newTodo.setTitle(newTodoText.getText().toString());
                newTodo.setIsCompleted(false);
                todoDAO.insert(newTodo);

                newTodoText.setText("");

                List<Todo> newTodos = todoDAO.getTodos();
                tAdapter.update(newTodos);
            }
        });
    }
}