package com.pdm.amarelo.room.entities;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@NoArgsConstructor
@Getter
@Setter
@Entity(tableName = "tickets")
public class Ticket {
	@PrimaryKey(autoGenerate = true)
	private Long id;

	private Long originId, destinationId, bookingId;
	private Double price;
}
