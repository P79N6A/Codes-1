import java.util.*;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        LinkedList<ArrayList<Integer> > ret = new LinkedList<ArrayList<Integer> >();
        sum = sum << 1;
        for (int i = 2; i * (i - 1) < sum; ++i) {
        	//System.out.println(i);
            int up = sum - (i - 1) * i;
            int down = 2 * i;
            if (up % down == 0) {
                ArrayList<Integer> temp = new ArrayList<Integer>();
                int cnt = i;
                for (int j = up / down; --cnt >= 0; ++j) {
                    temp.add(j);
                }
                ret.addFirst(temp);
            }
        }
        return new ArrayList<ArrayList<Integer> >(ret);
    }
}