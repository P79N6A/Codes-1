import java.util.*;

public class Solution {
    public static String PrintMinNumber(int [] numbers) {
    	ArrayList<Integer> al = new ArrayList<>();
    	for (int i : numbers) {
    		al.add(i);
    	}
    	Collections.sort(al, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				String s1 = o1 + "" + o2;
				String s2 = o2 + "" + o1;
				return s1.compareTo(s2);
			}
		});
    	
    	StringBuilder sb = new StringBuilder();
    	for (int i : al) {
    		sb.append(String.valueOf(i));
    	}
    	return sb.toString();
    }
}