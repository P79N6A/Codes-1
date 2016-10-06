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
const int MAXN = 111;

struct P {
    int x, y;
}p[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

bool dfs(int x, int y) {
    if (x == y) return 1;
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); ++i) {
        int v = G[x][i];
        if (vis[v]) continue;
        vis[v] = 1;
        if (dfs(v, y)) return 1;
    }
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, op, x, y, cnt = 0; cin >> n;
    while (n--) {
        cin >> op >> x >> y;
        if (op == 1) {
            p[cnt].x = x, p[cnt].y = y;
            for (int i = 0; i < cnt; ++i) {
                if ((x < p[i].x && p[i].x < y) || (x < p[i].y && p[i].y < y)) {
                    G[i].push_back(cnt);
                }
                if ((p[i].x < x && x < p[i].y) || (p[i].x < y && y < p[i].y)) {
                    G[cnt].push_back(i);
                }
            }
            ++cnt;
        }
        else {
            --x, --y;
            memset(vis, 0, sizeof vis);
            if (dfs(x, y)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
