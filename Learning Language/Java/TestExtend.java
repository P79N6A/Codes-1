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
		// �������ʽ���ã���ô�������ô���ã�super()�����ø�����޲ι��캯��
		// ���ù��췽��ʱ��ֻ�ܷ��ڵ�һ��
		super("Alice", 12);
		this.school = school;
		System.out.println(super.talk() + this.talk());
	}
	
	// ��д�����еķ���talk()
	// �����Ȩ�޲���С�ڸ����е�ͬ������
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