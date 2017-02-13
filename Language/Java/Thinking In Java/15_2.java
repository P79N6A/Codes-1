class Holder<T> {
	private T a, b, c;
	
	public Holder(T a, T b, T c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public void set(T a, T b, T c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public T geta() {
		return a;
	}
}

public class Main {
    public static void main(String[] args) {
    	Holder<Integer> h = new Holder(1, 2, 3);
    	System.out.println(h.geta());
    }
}