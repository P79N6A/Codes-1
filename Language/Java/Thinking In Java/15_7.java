import java.util.Iterator;

class Fibonacci {
	private int count = 0;
	public int fib(int n) {
		if (n < 2) return 1;
		else return fib(n - 1) + fib(n - 2);
	}
	public int next() {
		return fib(count++);
	}
}

class IterableFibonacci implements Iterable<Integer> {
	private int n;
	private Fibonacci f = new Fibonacci();
	public IterableFibonacci(int n) { this.n = n;}
	
	@Override
	public Iterator<Integer> iterator() {
		return new Iterator<Integer>() {
			@Override
			public boolean hasNext() { return n > 0; }
			@Override
			public Integer next() {
				--n;
				return f.next();
			}
		};
	}
}

public class Main {
    public static void main(String[] args) {
    	for (int i : new IterableFibonacci(10)) {
    		System.out.println(i);
    	}
    }
}