import java.util.*;

public class ArrayPractice {
	public static void main(String[] args) {
		// initial array
		int a[][] = {
			{1, 2, 3, 4, 5},
			{1, 3, 5}
		};

		System.out.println("a's length = " + a.length);
		System.out.println("a[0]'s length = " + a[0].length);
		System.out.println("a[1]'s length = " + a[1].length);
		// invalid: a[1][4] = 6; (out of range)

		int b[][] = new int[2][5];
		System.arraycopy(a, 0, b, 0, a.length);
		System.out.println("b[0]'s length = " + b[0].length);
		System.out.println("b[1]'s length = " + b[1].length);
		a[0][0] = 3;
		for (int i = 0; i < b.length; ++i) {
			for (int j = 0; j < b[i].length; ++j) {
				System.out.print(b[i][j] + " ");
			}
			System.out.println();
		}
		// This means when copying two-dimensional array we just copy its address.
		// But this conclusion is not suitable for one-dimensional array

		int org[] = {4, 9, 0, 2, 11, 34, 5, 56, 22};
		System.out.println("The orige array: ");
		for (int i = 0; i < org.length; ++i) {
			System.out.print(org[i] + " ");
		}
		System.out.println();

		Arrays.sort(org);
		System.out.println("After sorting: ");
		for (int i = 0; i < org.length; ++i) {
			System.out.print(org[i] + " ");
		}
		System.out.println();
		
		int c[][][] = new int[2][3][4];
		System.out.println("3-dimensinal array: ");
		System.out.println("Size is : " + c[0][0].length);
	}
}
