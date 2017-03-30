public class Solution {
	public static int GetUglyNumber_Solution(int index) {
		int[] ans = new int[index + 2];
		ans[1] = 1;
		int cnt2 = 1, cnt3 = 1, cnt5 = 1;
		for (int i = 2; i <= index; ++i) {
			int n2 = ans[cnt2] * 2, n3 = ans[cnt3] * 3, n5 = ans[cnt5] * 5;
			ans[i] = Math.min(Math.min(n2, n3), n5);
			if (ans[i] == n2) {
				++cnt2;
			}
			if (ans[i] == n3) {
				++cnt3;
			}
			if (ans[i] == n5) {
				++cnt5;
			}
		}
        return ans[index];
    }
}