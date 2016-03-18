#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

bool have[30];

int main()
{
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.length(); ++i) {
            have[s[i] - 'a'] = 1;
        }
        int i = 25, last = 0;
        string ans;
        while (1) {
            int mx = -1;
            for (; i >= 0; --i) {
                if (have[i]) {
                    have[i] = 0;
                    mx = i;
                    break;
                }
            }
            if (mx == -1) break;

            for (int j = last; j < s.length(); ++j) {
                if (s[j] == mx + 'a') {
                    ans += s[j];
                    last = j;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
