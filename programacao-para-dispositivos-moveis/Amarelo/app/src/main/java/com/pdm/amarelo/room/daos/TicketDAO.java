package com.pdm.amarelo.room.daos;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Transaction;
import androidx.room.Update;

import com.pdm.amarelo.room.entities.Ticket;
import com.pdm.amarelo.room.relations.TicketAndCities;

import java.util.List;

@Dao
public interface TicketDAO {
	@Insert
	public void insert(Ticket... tickets);

	@Update
	public void update(Ticket... tickets);

	@Delete
	public void delete(Ticket ticket);

	@Transaction
	@Query("SELECT * FROM tickets")
	public List<TicketAndCities> getTickets();

	@Transaction
	@Query("SELECT * FROM tickets WHERE id = :ticketId")
	public TicketAndCities getTicketById(Long ticketId);
}
