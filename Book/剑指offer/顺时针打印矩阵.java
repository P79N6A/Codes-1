import java.util.ArrayList;
public class Solution {
    public static ArrayList<Integer> printMatrix(int [][] matrix) {
        if (matrix.length == 0) return null;
        ArrayList<Integer> ret = new ArrayList<>();
        int x = matrix.length, y = matrix[0].length;
        for (int i = 0; i < y; ++i) {
            ret.add(matrix[0][i]);
        }
        int nx = 0, ny = y - 1;
        boolean col = true;
        int xd = 1;
        int yl = -1;
        while (true) {
            if (col) {
                if (--x == 0) break;
                for (int i = 0; i < x; ++i) {
                    nx += xd;
                    ret.add(matrix[nx][ny]);
                }
                xd = -xd;
            }
            else {
                if (--y == 0) break;
                for (int i = 0; i < y; ++i) {
                    ny += yl;
                    ret.add(matrix[nx][ny]);
                }
                yl = -yl;
            }
            col = !col;
        }
        return ret;
    }
	public static void main(String[] args) {
		int[][] x = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		System.out.println(printMatrix(x));
	}
}