abstract class Shape {
	void draw() { System.out.println(this + ".draw()");}
	abstract public String toString();
}

class Circle extends Shape {
	public String toString() {
		return "Circle";
	}
}

class Rhomboid extends Shape {
	public String toString() {
		return "Rhomboid";
	}
}

public class Main {
	private static void familyTree(Class<?> c) {
		if (c == null) return;
		System.out.println(c.getName());
		for (Class<?> k : c.getInterfaces()) {
			System.out.print("Interface: " + k.getName());
			familyTree(k.getSuperclass());
		}
		familyTree(c.getSuperclass());
	}
    public static void main(String[] args) throws Exception {
    	familyTree(Class.forName("Circle"));
    }
}