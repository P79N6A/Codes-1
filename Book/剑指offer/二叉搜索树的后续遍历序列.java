public class Solution {
    public static boolean check(int[] a, int bg, int ed) {
        if (bg >= ed) return true;
        int root = a[ed--];
        int i = 0;
        for (i = ed; i >= bg; --i) {
            if (a[i] < root) {
                break;
            }
        }
		for (int j = bg; j <= i; ++j) {
			if (a[j] > root) return false;
		}
        return check(a, i + 1, ed) && check(a, bg, i);
    }
    
    public static boolean VerifySquenceOfBST(int [] sequence) {
        if (sequence.length == 0) return false;
        return check(sequence, 0, sequence.length - 1);
    }
}