import java.lang.Math;

public class EditDistance {

    private static int countDistance(String a, String b) {
        a = 'a' + a;
        b = 'a' + b;
        char[] ca = a.toCharArray();
        char[] cb = b.toCharArray();
        int[][] dp = new int[ca.length][cb.length];
        for (int i = 1; i < ca.length; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i < cb.length; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i < ca.length; ++i) {
            for (int j = 1; j < cb.length; ++j) {
                if (ca[i] == cb[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    // abc-efgh -> abc-efg + 插入h到b串;
                    // abc-efgh -> ab-efgh + 删除a串中的c;
                    // abc-efgh -> ab-efg + 替换c为h;
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
            }
        }
        return dp[ca.length - 1][cb.length - 1];
    }

    public static void main(String[] args){
        System.out.println(countDistance("abc", "efgh"));
    }
 }