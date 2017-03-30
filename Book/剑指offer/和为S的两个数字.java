import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] a,int sum) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        int l = 0, r = a.length - 1;
        while (l < r) {
            if (a[l] + a[r] == sum) {
                ret.add(a[l]);
                ret.add(a[r]);
                break;
            }
            while (l < r && a[l] + a[r] < sum) ++l;
            while (l < r && a[l] + a[r] > sum) --r;
        }
        return ret;
    }
}