interface Person {
	String name = "Alice"; // 默认final修饰
	int age = 20;
	public String talk(); // 默认abstract
}

class Student implements Person {
	public String talk() {
		return "haha";
	}
}

public class TestInterface {
	public static void main(String[] args) {
		Student s = new Student();
		System.out.println(s.talk());
	}
}