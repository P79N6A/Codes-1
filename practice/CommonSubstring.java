/*
 * 最原始的做法，找出所有串匹配，复杂度n^4
 * 考虑匹配开始位置，复杂度降为n^3
 * 使用动态规划 n^2
 * 在使用滚动数组，空间降为n
 * 考虑状态更新为对角线，可以优化到空间为1
 * http://www.cnblogs.com/ider/p/longest-common-substring-problem-optimization.html
 */
public class CommonSubstring {

    private static int countCommon(String a, String b) {
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();
        int dp[][] = new int[ca.length][cb.length];
        for (int i = 0; i < ca.length; ++i) dp[i][0] = ca[i] == cb[0]? 1: 0;
        for (int i = 0; i < cb.length; ++i) dp[0][i] = ca[0] == cb[i]? 1: 0;
        int ans = 0;
        for (int i = 1; i < ca.length; ++i) {
            for (int j = 1; j < cb.length; ++j) {
                if (ca[i] == cb[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(countCommon("cabc", "efabccabcccg"));
    }
}