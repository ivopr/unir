package com.pdm.todo.room.daos;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import com.pdm.todo.room.entities.Todo;

import java.util.List;

@Dao
public interface TodoDAO {
    @Insert
    public void insert(Todo... todos);

    @Update
    public void update(Todo... todos);

    @Delete
    public void delete(Todo todo);

    @Query("SELECT * FROM todos WHERE id = :idToFind")
    public Todo getTodo(Long idToFind);

    @Query("SELECT * FROM todos")
    public List<Todo> getTodos();
}