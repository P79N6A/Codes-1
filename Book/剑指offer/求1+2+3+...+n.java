public class Solution {
    public int Sum_Solution(int n) {
        boolean stop = (n != 0 && (n += Sum_Solution(n - 1)) != 0);
        return n;
    }
}