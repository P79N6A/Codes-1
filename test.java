public class test {
	public static void main(String[] args) {
		int b = 20;
		int a[] = new int[b];
		a[15] = 1;
		for (int i: a) {
			System.out.print(i);
		}
	}
}