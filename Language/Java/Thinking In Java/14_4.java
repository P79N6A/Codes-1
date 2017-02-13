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
    public static void main(String[] args) {
    	Rhomboid r = new Rhomboid();
    	r.draw();
    	Shape s = r;
    	s.draw();
    	r = (Rhomboid)s;
    	r.draw();
    	System.out.println(s instanceof Shape);
    	System.out.println(s instanceof Rhomboid);
    	Circle c = (Circle)s;
    	c.draw();
    }
}