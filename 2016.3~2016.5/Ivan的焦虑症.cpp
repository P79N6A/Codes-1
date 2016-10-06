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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 41;

int a[5][MAXN];
bool vis[5][MAXN];
int cur[5];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, x, t;
    while (cin >> n >> x) {
        for (int i = 1; i <= n; ++i) cin >> cur[i];
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            cin >> t;
            for (int j = 0; j < t; ++j) cin >> a[i][j], vis[i][a[i][j]] = 1;
            if (i > 1) cout << ' ';
            int ans = 0;
            int tar = x;
            if (cur[i] < tar) {
                for (int j = cur[i] + 1; j <= tar; ++j) {
                    ans += 5;
                    if (j != tar && vis[i][j]) {
                        ans += 15;
                    }
                }
            }
            else if (cur[i] > tar) {
                for (int j = cur[i] - 1; j >= tar; --j) {
                    ans += 5;
                    if (j != tar && vis[i][j]) {
                        ans += 15;
                    }
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
