package src.elements;

import java.util.Calendar;

public class Person {
	private String name;
	private int birthYear;

	public Person() {
		this.name = "";
		this.birthYear = 0;
	}

	public Person(String name, int year) {
		this.name = name;
		this.birthYear = year;
	}

	public String toString() {
		return (
			"Name: " + this.name +
			"\nAge: " + this.getAge()
		);
	}

	public int getAge() {
		return Calendar.getInstance().get(Calendar.YEAR) - this.birthYear;
	}
}
