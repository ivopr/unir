package com.pdm.rivaldalocaliza.room.models;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@Getter
@Setter
@Entity(tableName = "user")
public class User {
	@PrimaryKey(autoGenerate = true)
	private Long id;
	private String name;
	private String email;
}
