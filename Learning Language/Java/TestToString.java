class Person extends Object {
	String name = "Alice";
	public String toString() {
		return name;
	}
}

public class TestToString {
	public static void main(String[] args) {
		Person p = new Person();
		System.out.println(p);
	}
}