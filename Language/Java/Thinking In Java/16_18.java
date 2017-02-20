import java.util.Arrays;

class X {
	public int x = 0;
	static int count = 0;
	public X() {
		this.x = count++;
	}
}

public class Solution {
	public static void main(String[] args) {
		int[] a = {1, 2, 3, 4};
		int[] b = {5, 6};
		System.arraycopy(a, 0, b, 0, 2);
		System.out.println(Arrays.toString(b));
		b[0] = 10;
		System.out.println(Arrays.toString(a));
		System.out.println(Arrays.toString(b));
		
		X[] aa = new X[1];
		X[] bb = new X[1];
		aa[0] = new X();
		bb[0] = new X();
		System.out.println(bb[0].x);
		System.arraycopy(aa, 0, bb, 0, 1);
		bb[0].x = 10;
		System.out.println(aa[0].x);
		System.out.println(bb[0].x);
	}
}