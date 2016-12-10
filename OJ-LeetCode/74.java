public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) return false;
        int r = matrix.length, c = matrix[0].length;
        int x = r - 1, y = 0;
        while (x > -1 && y < c) {
            if (matrix[x][y] > target) {
                --x;
            }
            else if (matrix[x][y] < target) {
                ++y;
            }
            else return true;
        }
        return false;
    }
}