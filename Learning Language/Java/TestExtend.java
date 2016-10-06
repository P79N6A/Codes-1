class Person {
	String name;
	int age;
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String talk() {
		return age + " " + name;
	}
}

class Student extends Person {
	String school;
	public Student(String school) {
		// 如果不显式调用，那么它则会这么调用：super()；调用父类的无参构造函数
		// 调用构造方法时，只能放在第一行
		super("Alice", 12);
		this.school = school;
		System.out.println(super.talk() + this.talk());
	}
	
	// 复写父类中的方法talk()
	// 其访问权限不能小于父类中的同名方法
	public String talk() {
		return " " + school;
	}
}

public class TestExtend {
	public static void main(String[] args) {
		Student s = new Student("CQU");
		//System.out.println("I'm " + s.name + ", " + s.age + " years old. " + "I'm from " + s.school + '.');
	}
}