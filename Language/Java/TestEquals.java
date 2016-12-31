class Person {
	private String name;
	private int age;
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	// 复写父类(Object)中的equals方法
	public boolean equals(Object o) {
		boolean temp = true;
		Person p1 = this;
		if (o instanceof Person) {
			Person p2 = (Person)o;
			if (!(p1.name.equals(p2.name) && p1.age == p2.age)) {
				temp = false;
			}
		}
		else {
			temp = false;
		}
		return temp;
	}
}

public class TestEquals {
	public static void main(String[] args) {
		String s1 = new String("Java");
		String s2 = new String("Java");
		//String s1 = "Java";
		//String s2 = "Java";
		if (s1 == s2) System.out.println("s1 == s2\n");
		if (s1.equals(s2)) System.out.println("s1 equals to s2\n");
		int a = 10, b = 10;
		if (a == b) System.out.println(a);
	}
}