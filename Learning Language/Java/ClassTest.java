class Person {
	private String name;
	private int age;
	
	public Person() {
		name = "默认";
		age = 0;
	}
	
	void talk() {
		System.out.println("I'm " + name + ", I'm " + age + " years old.");
	}
	
	public void setName(String na) {
		name = na;
	}
	
	public void setAge(int ag) {
		if (ag > 0) // use if to avoid invalid input
			age = ag;
	}
}

public class ClassTest {
	public static void main(String[] args) {
		boolean flag = true;  // can not assign number to it
		Person p = new Person();
		p.setName("郭子尧");
		p.setAge(20);
		p.talk();
		Person p2 = null;
		p2 = p; // 只是传递了地址
		p2.setAge(10);
		p.talk();
		new Person().talk(); // 匿名类
	}
}