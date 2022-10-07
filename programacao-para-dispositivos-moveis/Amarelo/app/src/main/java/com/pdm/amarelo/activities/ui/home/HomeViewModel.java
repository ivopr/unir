package com.pdm.amarelo.activities.ui.home;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModel;

import com.pdm.amarelo.room.relations.BookingAndTickets;

import java.util.List;

public class HomeViewModel extends ViewModel {
	private MutableLiveData<List<BookingAndTickets>> bookingAndTickets;

	public HomeViewModel() {
		bookingAndTickets = new MutableLiveData<>();
	}

	public void setBookingAndTickets(List<BookingAndTickets> list) {
		bookingAndTickets.setValue(list);
	}

	public LiveData<List<BookingAndTickets>> getBookingAndTickets() {
		return bookingAndTickets;
	}
}