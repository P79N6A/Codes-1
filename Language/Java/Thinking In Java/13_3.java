import java.util.Formatter;

public class Main {
    public static void main(String[] args) {
    	Turtle alice = new Turtle("alice", new Formatter(System.out));
    	Turtle bob = new Turtle("bob", new Formatter(System.err));
    	alice.move(0,0);
    	alice.move(1,1);
    	bob.move(5, 5);
    	bob.move(6, 6);
    }
}

class Turtle {
	private String name;
	private Formatter f;
	public Turtle(String name, Formatter f) {
		this.name = name;
		this.f = f;
	}
	void move(int x, int y) {
		f.format("%s move to (%d, %d).\n", name, x, y);
	}
}