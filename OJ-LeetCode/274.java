import java.util.*;
public class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int up = n - lowerBound(citations, 0, n - 1, mid);
            int down = n - upperBound(citations, 0, n - 1, mid);
            //System.out.println(up + " " + down + " " + mid);
            if (down <= mid && mid <= up) {
                ans = mid;
                l = mid + 1;
            }
            else if (mid > up) {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    public static int lowerBound(int[] a, int l, int r, int key) {
        int ret = r + 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int cmp = a[mid] - key;
            if (cmp >= 0) {
                ret = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ret;
    }
    
    public static int upperBound(int[] a, int l, int r, int key) {
        int ret = r + 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            int cmp = a[mid] - key;
            if (cmp > 0) {
                ret = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ret;
    }
}