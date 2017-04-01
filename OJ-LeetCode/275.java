
public class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int l = 0, r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (citations[n - mid - 1] > mid) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans + 1;
    }
 
}