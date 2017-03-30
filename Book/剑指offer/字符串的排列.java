import java.util.*;

public class Main {
	private static ArrayList<String> ans;
	
	public static void getPermutation(int bg, char[] str) {
		if (bg == str.length) {
			ans.add(new String(str));
		}
		for (int i = bg; i < str.length; ++i) {
			if (bg != i && str[bg] == str[i]) continue;
			swap(str, bg, i);
			getPermutation(++bg, str);
			--bg;
			swap(str, bg, i);
		}
	}
	
	public static void swap(char[] s, int x, int y) {
		char temp = s[x];
		s[x] = s[y];
		s[y] = temp;
	}
	
    public static ArrayList<String> Permutation(String str) {
    	ans = new ArrayList<>();
    	if (str != null && str.length() > 0) {
    		getPermutation(0, str.toCharArray());
    	}
    	String[] ss = ans.toArray(new String[ans.size()]);
    	Arrays.sort(ss);
    	for (int i = 0; i < ss.length; ++i) {
    		ans.set(i, ss[i]);
    	}
    	return ans;
    }
    
    public static void main(String[] args) {
    	System.out.println(Permutation("abc"));
    }
}