package com.pdm.amarelo.room;

import androidx.room.Database;
import androidx.room.RoomDatabase;

import com.pdm.amarelo.room.daos.BookingDAO;
import com.pdm.amarelo.room.daos.CityDAO;
import com.pdm.amarelo.room.daos.TicketDAO;
import com.pdm.amarelo.room.entities.Booking;
import com.pdm.amarelo.room.entities.City;
import com.pdm.amarelo.room.entities.Ticket;

@Database(entities = {Booking.class, City.class, Ticket.class}, version = 1)
public abstract class AppDb extends RoomDatabase {
	public abstract BookingDAO getBookingDAO();
	public abstract CityDAO getCityDAO();
	public abstract TicketDAO getTicketDAO();
}
