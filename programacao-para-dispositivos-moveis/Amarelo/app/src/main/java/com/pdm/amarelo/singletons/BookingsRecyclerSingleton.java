package com.pdm.amarelo.singletons;

import com.pdm.amarelo.adapters.BookingsAdapter;
import com.pdm.amarelo.room.relations.BookingAndTickets;

import java.util.List;

public class BookingsRecyclerSingleton {
	private static volatile BookingsAdapter adapter;

	private static BookingsAdapter create(List<BookingAndTickets> list) {
		return new BookingsAdapter(list);
	}

	public static synchronized BookingsAdapter getAdapter(
		List<BookingAndTickets> list
	) {
		if (adapter == null) {
			adapter = create(list);
		}

		return adapter;
	}
}
