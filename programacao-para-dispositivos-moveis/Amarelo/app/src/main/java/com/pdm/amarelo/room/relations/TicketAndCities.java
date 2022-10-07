package com.pdm.amarelo.room.relations;

import androidx.room.Embedded;
import androidx.room.Relation;

import com.pdm.amarelo.room.entities.City;
import com.pdm.amarelo.room.entities.Ticket;

public class TicketAndCities {
	@Embedded public Ticket ticket;
	@Relation(
		parentColumn = "originId",
		entityColumn = "id"
	)
	public City origin;
	@Relation(
		parentColumn = "destinationId",
		entityColumn = "id"
	)
	public City destination;
}
