package com.pdm.amarelo.room.daos;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Transaction;
import androidx.room.Update;

import com.pdm.amarelo.room.entities.Booking;
import com.pdm.amarelo.room.relations.BookingAndTickets;

import java.util.List;

@Dao
public interface BookingDAO {
	@Insert
	public void insert(Booking... bookings);

	@Update
	public void update(Booking... bookings);

	@Delete
	public void delete(Booking booking);

	@Transaction
	@Query("SELECT * FROM bookings")
	public List<BookingAndTickets> getBookings();

	@Transaction
	@Query("SELECT * FROM bookings WHERE id = :bookingId")
	public BookingAndTickets getBookingById(Long bookingId);
}
