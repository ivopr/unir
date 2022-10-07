package com.pdm.amarelo.room.entities;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@Getter
@Setter
@Entity(tableName = "cities")
public class City {
	@PrimaryKey(autoGenerate = true)
	private Long id;

	private String name, airport;
}
