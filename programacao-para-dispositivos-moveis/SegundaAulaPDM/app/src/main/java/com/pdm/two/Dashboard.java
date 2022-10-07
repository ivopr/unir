package com.pdm.two;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.widget.TextView;

import java.util.ArrayList;

public class Dashboard extends AppCompatActivity {
	ArrayList<Contact> contacts;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_dashboard);

		// Lookup the recyclerview in activity layout
		RecyclerView rvContacts = (RecyclerView) findViewById(R.id.rvContacts);

		// Initialize contacts
		contacts = Contact.createContactsList(20);
		// Create adapter passing in the sample user data
		ContactsAdapter adapter = new ContactsAdapter(contacts);
		// Attach the adapter to the recyclerview to populate items
		rvContacts.setAdapter(adapter);
		// Set layout manager to position the items
		rvContacts.setLayoutManager(new LinearLayoutManager(this));
		// That's all!
	}
}