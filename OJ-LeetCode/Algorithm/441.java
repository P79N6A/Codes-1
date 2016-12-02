public class Solution {
    public int arrangeCoins(int n) {
        long up = n * 2L, i = 1;
        while (i * (i + 1) <= up) ++i;
        return (int)i - 1;
    }
}