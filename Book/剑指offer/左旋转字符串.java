public class Solution {
    public String LeftRotateString(String str,int n) {
        if (str.length() == 0) return "";
        int len = str.length();
        n %= len;
        char[] s = new char[len];
        int index = 0;
        for (int i = n; i < len; ++i) {
            s[index++] = str.charAt(i);
        }
        for (int i = 0; i < n; ++i) {
            s[index++] = str.charAt(i);
        }
        return new String(s);
    }
}