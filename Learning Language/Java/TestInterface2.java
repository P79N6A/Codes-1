interface USB {
	public void start();
	public void stop();
}

class MoveDisk implements USB {
	public void start() {
		System.out.println("MoveDisk start...");
	}
	public void stop() {
		System.out.println("MoveDisk stop...");
	}
}

class Computer {
	public void work(USB u) {
		u.start();
		u.stop();
	}
}

public class TestInterface2 {
	public static void main(String[] args) {
		new Computer().work(new MoveDisk());
	}
}