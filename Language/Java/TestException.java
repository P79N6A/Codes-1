public class TestException {
	public static void main(String[] args) {
		try {
			int a[] = new int[5];
			a[10] = 1;
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Array out of range.");
			System.out.println("Exception: " + e);
		}
		finally {
			System.out.println("Must enter here~");
		}
		System.out.println("End of main()");
	}
}