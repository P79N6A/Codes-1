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
const int MAXN = 511;

int mp[50][50], cnt, link[MAXN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char org[50][50];
vector<int> G[MAXN];
bool vis[MAXN];

bool dfs(int x) {
    for (int i = 0; i < G[x].size(); ++i) {
        int v = G[x][i];
        if (!vis[v]) {
            vis[v] = 1;
            if (!link[v] || dfs(link[v])) {
                link[v] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, h, w; scanf("%d", &t);
    while (t --) {
        cnt = 0;
        scanf("%d%d", &h, &w);
        for (int i = 1; i <= h * w; ++i) G[i].clear();
        for (int i = 0; i < h; ++i) {
            scanf("%s", org[i]);
            for (int j = 0; j < w; ++j) {
                if (org[i][j] == '*') mp[i][j] = ++cnt;
                else mp[i][j] = 0;
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (mp[i][j]) {
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (0 <= nx && nx < h && 0 <= ny && ny < w && mp[nx][ny]) {
                            G[mp[i][j]].push_back(mp[nx][ny]);
                        }
                    }
                }
            }
        }

        int ans = 0;
        memset(link, 0, sizeof link);
        for (int i = 1; i <= cnt; ++i) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) ++ans;
        }

        printf("%d\n", cnt - ans / 2);
    }
    return 0;
}
