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
const int MAXN = 1e6 + 111;

int sg[MAXN];
bool vis[MAXN];

int mex(int x) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= x; ++i) {
        vis[sg[x - i]] = 1;
    }
    if (x >= 3) {
        for (int i = 1; i <= x - 2; ++i) {
            for (int j = i; j + i <= x - 1; ++j) {
                int k = x - i - j;
                // 子状态的sg异或和是母状态
                vis[sg[i] ^ sg[j] ^ sg[k]] = 1;
            }
        }
    }
    for (int i = 0; ; ++i) if (!vis[i]) return i;
}

void playtable() {
    sg[0] = 0;
    for (int i = 1; i <= 100; ++i) {
        sg[i] = mex(i);
    }
    for (int i = 0; i < 30; ++i) {
        printf("%d %d\n", i, sg[i]);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
//    playtable();
    int t, n, x; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (x != 0 && x % 8 == 0) {
                sum ^= x - 1;
            }
            else if ((x + 1) % 8 == 0) {
                sum ^= x + 1;
            }
            else sum ^= x;
        }
        if (sum) puts("First player wins.");
        else puts("Second player wins.");
    }
    return 0;
}
