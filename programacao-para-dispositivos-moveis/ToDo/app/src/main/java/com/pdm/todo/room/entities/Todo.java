package com.pdm.todo.room.entities;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@Getter
@Setter
@Entity(tableName = "todos")
public class Todo {
    @PrimaryKey(autoGenerate = true)
    private Long id;
    private String title;
    private Boolean isCompleted;
}
