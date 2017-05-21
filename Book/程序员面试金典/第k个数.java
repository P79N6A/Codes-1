import java.util.*;

// 从小到大排列数组
public class KthNumber {
    public int findKth(int k) {
        int k3 = 0, k5 = 0, k7 = 0;
        int[] ans = new int[k + 1];
        ans[0] = 1;
        for (int i = 1; i <= k; ++i) {
            ans[i] = Math.min(ans[k3] * 3, Math.min(ans[k5] * 5, ans[k7] * 7));
            if (ans[i] == ans[k3] * 3) ++k3;
            if (ans[i] == ans[k5] * 5) ++k5;
            if (ans[i] == ans[k7] * 7) ++k7;
        }
        return ans[k];
    }
}