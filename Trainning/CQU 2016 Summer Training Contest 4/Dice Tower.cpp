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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

bool vis[7];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x, l, r;
    cin >> n >> x;
    bool flag = 1;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        if (flag) {
            memset(vis, 0, sizeof vis);
            vis[l] = vis[7 - l] = vis[r] = vis[7 - r] = 1;
            vis[x] = 1;
            int cnt = 0;
            for (int i = 1; i <= 6; ++i) {
                if (!vis[i]) {
                    x = i;
                    ++cnt;
                }
            }
            if (cnt > 1) flag = 0;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
