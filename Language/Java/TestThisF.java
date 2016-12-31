class Person {
	string name;
	int age;
	
	public Person(string name, int age) {
		this.age = age;
		this.name = name;
		this(); // illegal
	}
	
	void talk() {
		this(); // illegal: must be used in constructor
		System.out.println("I can talk!");
	}
}

public class TestThisF {
	public static void main() {
		Person a = new Person();
		a.talk();
	}
}