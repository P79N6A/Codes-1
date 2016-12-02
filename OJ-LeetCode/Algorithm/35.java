public class Solution {
    public int searchInsert(int[] nums, int target) {
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) return i;
        }
        if (nums[0] > target) return 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] < target && target < nums[i + 1]) return i + 1;
        }
        return nums.length;
    }
}