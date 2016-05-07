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
const int MAXN = 1e4 + 111;

bool vis[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    char s[10];
    while (~scanf("%d", &n) && n) {
        memset(vis, 0, sizeof vis);
        vis[n] = 1;
        while (1) {
            n *= n;
            int cnt = 0, x = n;
            while (x) {
                x /= 10;
                ++cnt;
            }
            if (cnt <= 2) {
                n = 0;
            }
            else {
                n = n % 1000000;
                n /= 100;
            }

            if (vis[n]) break;
            vis[n] = 1;
        }

        int ans = 0;
        for (int i = 0; i <= 10000; ++i) if (vis[i]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
