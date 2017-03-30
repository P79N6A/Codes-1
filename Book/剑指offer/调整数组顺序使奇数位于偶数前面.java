public class Solution {
	public void reOrderArray(int [] array) {
		int l = 0;
        for (int i = 0; i < array.length; ++i) {
        	if (array[i] % 2 == 1) {
        		for (int j = i; j > l; --j) {
        			int temp = array[j];
        			array[j] = array[j - 1];
        			array[j - 1] = temp;
        		}
        		++l;
        	}
        }
    }
}