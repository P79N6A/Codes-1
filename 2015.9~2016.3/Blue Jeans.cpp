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
const int MAXN = 3e5 + 111;

string s[20];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, m; cin >> t;
    while (t --) {
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
        }
        string ans;
        bool flag = 0;
        for (int j = 3; j <= 60; ++j) {
            for (int k = 0; k <= 60 - j; ++k) {
                bool ok = 1;
                string temp = s[0].substr(k, j);
                for (int i = 1; i < m; ++i) {
                    if (s[i].find(temp) == string::npos) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    flag = 1;
                    if (ans.size() < temp.size()) ans = temp;
                    else if (ans.size() == temp.size()) {
                        if (ans > temp) ans = temp;
                    }
                }
            }
        }

        if (flag) cout << ans << '\n';
        else cout << "no significant commonalities\n";
    }
    return 0;
}
