package com.pdm.amarelo.room.entities;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@Getter
@Setter
@Entity(tableName = "bookings")
public class Booking {
	@PrimaryKey(autoGenerate = true)
	private Long id;

	private Long departure, arrival;
	private Integer adults, babies, children;
}
