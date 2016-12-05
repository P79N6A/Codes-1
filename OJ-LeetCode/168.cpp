class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n != 0) {
            char add = 'A' + n % 26 - 1;
            if (n % 26 == 0) add = 'Z';
            ans = add + ans;
            n /= 26;
        }
        // reverse(ans.begin(), ans.end());
        for (int i = ans.length() - 1; i >= 0; --i) {
            if (ans[i] == 'Z') {
                int p = i;
                while (ans[p] == 'Z') {
                    --p;
                }
                // 借位
                if (ans[p] == 'A') {
                    --p;
                    if (p >= 0 && ans[p] == 'A') ans[p] = 'Z';
                    ans.erase(p + 1, 1);
                }
                else ans[p] -= 1;
                break;
            }
        }
        return ans;
    }
};