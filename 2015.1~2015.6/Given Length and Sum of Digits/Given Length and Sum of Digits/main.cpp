#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int m, s; cin >> m >> s;
    string ans;
    if (m * 9 < s || (s == 0 && m > 1))
        cout << -1 << ' ' << -1 << '\n';
    else {
        int num = s / 9;
        int lef = s % 9;
        if (num == 0 && lef)
        {
            ans += lef + '0';
            for (int i = 0; i < m - 1; ++i)
                ans += '0';
        }
        else if (num != 0)
        {
            for (int i = 0; i < num; ++i)
                ans += '9';
            if (num != m)
                ans += lef + '0';
            for (int i = 0; i < m - num - 1; ++i)
                ans += '0';
        }
        else if (m == 1 && s == 0)
            ans += '0';
        string mx = ans;
        reverse(ans.begin(), ans.end());
        if (ans[0] == '0')
        {
        for (int i = 0; i < m; ++i)
        {
            if (ans[i] != '0')
            {
                ans[0] = '1';
                ans[i] = ans[i] - 1;
                break;
            }
        }
        }
        cout << ans << ' ' << mx << '\n';
    }
    return 0;
}
