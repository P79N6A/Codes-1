public class Solution {
    public String replaceSpace(StringBuffer str) {
        String ret = "";
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                ret += "%20";
            }
            else ret += str.charAt(i);
        }
        return ret;
    }
}