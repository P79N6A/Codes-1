public class Solution {
    public int JumpFloor(int target) {
        int[] ans = new int[target + 3];
        ans[1] = 1, ans[2] = 2;
        for (int i = 3; i <= target; ++i) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans[target];
    }
}