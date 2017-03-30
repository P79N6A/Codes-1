public class Solution {
    
    private boolean isInteger(char[] str, int s, int e, boolean open) {
    	if (s == e) return false;
        if (open && (str[s] == '+' || str[s] == '-')) ++s;
        for (int i = s; i < e; ++i) {
            if (str[i] > '9' || str[i] < '0') return false;
        }
        return true;
    }
    
    private boolean isDecimal(char[] str, int s, int e) {
    	if (s == e) return false;
        if (str[s] == '+' || str[s] == '-') ++s;
        int cnt = 0;
        for (int i = s; i < e; ++i) {
            if (str[i] == '.' && i != 0 && i != e - 1) {
                ++cnt;
                continue;
            }
            if (str[i] == '.') return false;
            if (str[i] > '9' || str[i] < '0') return false;
        }
        return cnt <= 1;
    }
    
    public boolean isNumeric(char[] str) {
        if (str == null) return false;
        for (int i = 0; i < str.length; ++i) {
            if (str[i] == 'e' || str[i] == 'E') {
                return isDecimal(str, 0, i) && isInteger(str, i + 1, str.length, true);
            }
        }
        for (int i = 0; i < str.length; ++i) {
            if (str[i] == '.') {
                return isInteger(str, 0, i, true) && isInteger(str, i + 1, str.length, false);
            }
        }
        return isInteger(str, 0, str.length, true);
    }
}