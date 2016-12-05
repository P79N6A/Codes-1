public class Solution {
    public String convertToTitle(int n) {
        String ans = "";
        while (n != 0) {
            // 默认有个A，所以减1
            char add = (char)('A' + (--n) % 26);
            ans = add + ans;
            n /= 26;
        }
        return ans;
    }
}