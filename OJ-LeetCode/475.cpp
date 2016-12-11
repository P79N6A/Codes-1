class Solution {
public:
    int findRadius(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int l = 0, ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (; l < n; ++l) {
                if (b[i] >= a[l]) {
                    ans = max(ans, b[i] - a[l]);
                }
                else break;
            }
            for (; l < n; ++l) {
                if (b[i + 1] <= a[l]) break;
                if (b[i + 1] - a[l] < a[l] - b[i]) break;
                else ans = max(ans, a[l] - b[i]);
            }
        }
        for (; l < n; ++l) ans = max(ans, abs(b[m - 1] - a[l]));
        return ans;
    }
};