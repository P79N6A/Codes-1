public class Solution {
	
	public boolean testMatch(char[] str, int s, char[] pattern, int p) {
		if (s == str.length && p == pattern.length) return true;
		if (s != str.length && p == pattern.length) return false;
		if (p != pattern.length - 1 && pattern[p + 1] == '*') {
			if (s != str.length && (str[s] == pattern[p] || pattern[p] == '.'))
				// 进入下次比对 | 放弃这次比对
				return testMatch(str, s + 1, pattern, p) || testMatch(str, s, pattern, p + 2);
			else 
				return testMatch(str, s, pattern, p + 2);
		}
		if (s != str.length && (str[s] == pattern[p] || pattern[p] == '.' ))
			return testMatch(str, s + 1, pattern, p + 1);
		return false;
	}
	
    public boolean match(char[] str, char[] pattern) {
        if (str == null || pattern == null) {
            return false;
        }
        
        return testMatch(str, 0, pattern, 0);
    }
}