package com.pdm.todo.room;

import androidx.room.Database;
import androidx.room.RoomDatabase;

import com.pdm.todo.room.daos.TodoDAO;
import com.pdm.todo.room.entities.Todo;

@Database(entities = {Todo.class}, version = 1)
public abstract class AppDb extends RoomDatabase {
    public abstract TodoDAO getTodoDAO();
}