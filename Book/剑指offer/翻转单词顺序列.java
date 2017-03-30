public class Solution {
    public String ReverseSentence(String str) {
    	if (str == null) return null;
        String[] s = str.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = s.length - 1; i >= 0; --i) {
            sb.append(s[i]);
            if (i != 0) 
                sb.append(" ");
        }
        if (s.length == 0)
        	sb.append(str);
        return sb.toString();
    }
}