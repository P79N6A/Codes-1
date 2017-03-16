public class Solution {
    public static int FindGreatestSumOfSubArray(int[] array) {
        int ans = array[0];
        int sum = 0;
        for (int i = 0; i < array.length; ++i) {
            if (sum < 0) sum = 0;
            sum += array[i];
            if (sum > ans) ans = sum;
        }
        return ans;
    }
}