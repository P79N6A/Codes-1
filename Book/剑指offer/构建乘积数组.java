import java.util.ArrayList;
public class Solution {
    public int[] multiply(int[] A) {
        if (A == null) return null;
        int[] B = new int[A.length];
        int[] l = new int[A.length];
        int[] r = new int[A.length];
        l[0] = A[0];
        for (int i = 1; i < A.length; ++i) {
            l[i] = l[i - 1] * A[i];
        }
        r[A.length - 1] = A[A.length - 1];
        for (int i = A.length - 2; i >= 0; --i) {
            r[i] = r[i + 1] * A[i];
        }
        for (int i = 0; i < A.length; ++i) {
            B[i] = 1;
            if (i > 0) B[i] *= l[i - 1];
            if (i < A.length - 1) B[i] *= r[i + 1];
        }
        return B;
    }
}