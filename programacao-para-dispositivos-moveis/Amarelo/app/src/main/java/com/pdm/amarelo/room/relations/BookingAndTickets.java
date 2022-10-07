package com.pdm.amarelo.room.relations;

import androidx.room.Embedded;
import androidx.room.Junction;
import androidx.room.Relation;

import com.pdm.amarelo.room.entities.Booking;
import com.pdm.amarelo.room.entities.Ticket;

import java.util.List;

public class BookingAndTickets {
	@Embedded public Booking booking;
	@Relation(
		entity = Ticket.class,
		parentColumn = "id",
		entityColumn = "bookingId"
	)
	public List<TicketAndCities> tickets;
}
