public class Solution {
    public int FirstNotRepeatingChar(String str) {
        int[] cnt = new int[256];
        char[] arry = str.toCharArray();
        for (char s : arry) {
            ++cnt[s];
        }
        for (int i = 0; i < arry.length; ++i) {
            if (cnt[arry[i]] == 1) return i;
        }
        return -1;
    }
}