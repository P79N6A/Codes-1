public class Solution {
    public int StrToInt(String str) {
        if (str == null) {
            return 0;
        }
        
        str =  str.trim();
        int result = 0;
        boolean negtive = false;
        int len = str.length();
        int radix = 10;
        int i = 0;
        if (len > 0) {
            if (str.charAt(0) == '-') {
                negtive = true;
                ++i;
            }
            while (i < len) {
                char cur = str.charAt(i);
                if (cur == '+' && i == 0) {
                    
                }
                else if ('0' <= cur && cur <= '9') {
                    result *= radix;
                    result -= cur - '0';
                }
                else {
                    result = 0;
                    break;
                }
                ++i;
            }
        }
        return negtive ? result : -result;
    }
}