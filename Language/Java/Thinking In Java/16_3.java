import java.util.Random;

public class Solution {
	static double[][] createTwoDimension(int x, int y, double l, double r) {
		double[][] ret = new double[x][y];
		Random rd = new Random();
		double del = r - l;
		if (l > r) del = -del;
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				ret[i][j] = l + del * rd.nextDouble();
			}
		}
		return ret;
	}
	static void print(double[][] arr) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[i].length; ++j) {
				System.out.printf("%.2f ", arr[i][j]);
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		print(createTwoDimension(2, 3, 10, 20));
	}
}