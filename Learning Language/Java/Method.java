public class Method {
	public static void main(String[] args) {
		print();
		System.out.println("I like Java~");
		print();
	}
	
	public static void print() {
		for (int i = 0; i < 20; ++i) System.out.print("*");
		System.out.println();
	}
}