class Person {
	String name;
	int age;
	public void talk() {
		System.out.println("I'm a person");
	}
	
	public static void print() {
		talk(); // illegal
	}
}

public class TestStaticF {
	public static void main() {
		
	}
}