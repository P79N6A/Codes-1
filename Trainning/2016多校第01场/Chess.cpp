/*
  状压存储所有状态，计算SG值
 */
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
const int MAXN = 2e6 + 111;

int sg[MAXN];

int get(int x) {
    int &ret = sg[x];
    if (ret != -1) return ret;
    bool vis[30] = {0};
    for (int i = 0; i <= 20; ++i) {
        if (x & (1 << i)) {
            int nxt = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (x & (1 << j)) continue;
                nxt = (x ^ (1 << i)) | (1 << j);
                break;
            }
            if (nxt == -1) continue;
            int temp = sg[nxt];
            if (temp == -1) {
                temp = sg[nxt] = get(nxt);
            }
            vis[temp] = 1;
        }
    }
    for (int i = 0; ; ++i) {
        if (!vis[i]) {
            return ret = i;
        }
    }
}

inline void init() {
    sg[0] = 0;
    for (int i = (1 << 20); i >= 1; --i) {
        sg[i] = get(i);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    memset(sg, -1, sizeof sg);
    init();
    int t, n, m, x;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int ans = 0;
        while (n --) {
            scanf("%d", &m);
            int temp = 0;
            for (int i = 0; i < m; ++i) {
                scanf("%d", &x);
                temp |= (1 << (20 - x));
            }
            ans ^= sg[temp];
        }
        if (!ans) puts("NO");
        else puts("YES");
    }
    return 0;
}
