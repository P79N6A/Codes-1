public class Solution {
    
    public int left(int[] arry, int l, int r, int k) {
        int ret = -1;
        while (l <= r) {
        	int mid = (r - l) / 2 + l;
            if (arry[mid] < k) {
                l = mid + 1;
            }
            else {
                if (arry[mid] == k) ret = mid;
                r = mid - 1;
            }
        }
        return ret;
    }
    
    public int right(int[] arry, int l, int r, int k) {
        int ret = -1;
        while (l <= r) {
        	int mid = (r - l) / 2 + l;
            if (arry[mid] <= k) {
                if (arry[mid] == k) ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ret;
    }
    
    public int GetNumberOfK(int [] array , int k) {
        if (array == null) return 0;
        int rt = right(array, 0, array.length - 1, k);
        if (rt == -1) return 0;
        return rt - left(array, 0, array.length - 1, k) + 1;
    }
}