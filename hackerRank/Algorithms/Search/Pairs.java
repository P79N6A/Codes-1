import java.io.*;
import java.util.*;

public class Solution {
	
	public static int findRight(int[] a, int L, int R, int cmp) {
		int l = L, r = R, ret = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] <= cmp) {
				if (a[mid] == cmp) ret = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		return ret;
	}
	
	public static int findLeft(int[] a, int L, int R, int cmp) {
		int l = L, r = R, ret = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] < cmp) {
				l = mid + 1;
			}
			else {
				if (a[mid] == cmp) ret = mid;
				r = mid - 1;
			}
		}
		return ret;
	}
	
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	int n = in.nextInt(), k = in.nextInt();
    	int[] a = new int[n];
    	for (int i = 0; i < n; ++i) {
    		a[i] = in.nextInt();
    	}
    	Arrays.sort(a);
    	int ans = 0;
    	for (int i = n - 1; i > -1; --i) {
    		if (a[i] - k <= 0) break;
    		int fnd = a[i] - k;
    		int right = findRight(a, 0, i - 1, fnd);
    		if (right != -1) ans += right - findLeft(a, 0, i - 1, fnd) + 1;
    	}
    	System.out.println(ans);
    }
}