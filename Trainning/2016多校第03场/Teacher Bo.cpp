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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

bool vis[MAXN];
int x[MAXN], y[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        memset(vis, 0, sizeof vis);
        bool ok = 0;
        for (int i = 0; i < n && !ok; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int xx = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if (vis[xx]) {
                    ok = 1;
                    break;
                }
                vis[xx] = 1;
            }
        }
        printf("%s\n", ok? "YES" : "NO");
    }
    return 0;
}
