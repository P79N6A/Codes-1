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
	private static void rotate(Shape s) {
		if (s instanceof Circle) {
			System.out.println("I can't");
		}
		else System.out.println("OK!");
	}
    public static void main(String[] args) {
    	rotate(new Circle());
    	rotate(new Rhomboid());
    }
}