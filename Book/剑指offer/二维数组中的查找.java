public class Solution {
	public boolean Find(int target, int [][] array) {
		if (array == null) return false;
		int i = array.length - 1, j = 0;
		while (i >= 0 && j < array[0].length) {
			if (array[i][j] == target) return true;
			if (array[i][j] < target) ++j;
			else --i;
		}
		return false;
	}
}