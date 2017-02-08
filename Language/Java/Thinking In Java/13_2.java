public class Main {
    public static void main(String[] args) {
    	System.out.println(new InfiniteRecursion());
    }
}

class InfiniteRecursion {
	@Override
	public String toString() {
		return "Infinite Address: " + super.toString() + '\n';
	}
}