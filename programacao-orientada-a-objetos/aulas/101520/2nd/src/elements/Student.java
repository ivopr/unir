package src.elements;

public class Student extends Person {
	private String id;
	private double t1, t2, end;

	public Student() {
		super();
		this.id = "";
		this.t1 = this.t2 = this.end = 0;
	}

	public Student(String name, int year, String id, double t1, double t2) {
		super(name, year);
		this.id = id;
		this.t1 = t1;
		this.t2 = t2;
		this.end = (this.t1 + this.t2) / 2;
	}

	public String getSituation() {
		if(this.end >= 6)
			return "Approved";
		else
			return "Reproved";
	}

	public String toString() {
		String s = super.toString() + 
			"\nID: " + this.id + 
			"\nTest 1: " + this.t1 +
			"\nTest 2: " + this.t2 +
			"\nFinal Score: " + this.end +
			"\nSituation: " + this.getSituation();
		return s;
	}
}
