public class Solution {
    public static int MoreThanHalfNum_Solution(int [] array) {
        int val = array[0], time = 1;
        for (int i = 1; i < array.length; ++i) {
            if (val == array[i]) {
                ++time;
            }
            else if (--time == 0) {
                val = array[i];
                ++time;
            }
        }
        int cnt = 0;
        for (int i = 0; i < array.length; ++i) {
            if (array[i] == val) {
                ++cnt;
            }
        }
        return cnt > array.length / 2 ? val : 0;
    }
}