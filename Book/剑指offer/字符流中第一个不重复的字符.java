import java.util.LinkedList;

public class Solution {
	
	private int[] time = new int[256];
    LinkedList<Character> ll = new LinkedList<>();
    
    //Insert one char from stringstream
    public void Insert(char ch)
    {
        if (++time[ch] == 1) ll.add(ch);
    }
  //return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
        while (ll.size() != 0) {
            char cur = ll.getFirst();
            if (time[cur] == 1) return cur;
            ll.pollFirst();
        }
    	return '#';
    }
}