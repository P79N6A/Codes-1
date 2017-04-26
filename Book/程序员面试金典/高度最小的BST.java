import java.util.*;

public class MinimalBST {
    public int buildMinimalBST(int[] vals) {
        return cal(0, vals.length - 1);
    }
    
    private static int cal(int s, int e) {
        if (s > e) return 0;
        if (s == e) return 1;
        int mid = (s + e) >> 1;
        return Math.max(cal(s, mid - 1), cal(mid + 1, e)) + 1;
    }
}