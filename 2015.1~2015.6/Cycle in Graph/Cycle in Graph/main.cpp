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
const int MAXN = 1e5 + 111;

int n, m, k, u, v;
vector<int> G[MAXN];
int vis[MAXN];
int pos[MAXN];
int finish = 0;
int ans[MAXN], cnt = 0;

bool dfs(int u, int f) {
    vis[u] = -1;
    ans[cnt++] = u;
    pos[u] = cnt - 1;
//    printf("%d <- %d, %d \n", u, f, cnt);
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == f || vis[v] == 1) continue;
        if (vis[v] == -1 && cnt - pos[v] >= k + 1) {
            finish = v;
            return 1;
        }
        if (!vis[v]) {
            if (dfs(v, u)) {
                return 1;
            }
        }
    }
    --cnt;
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    while (m --) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i, i)) {
            break;
        }
    }
    printf("%d\n", cnt - pos[finish]);
    for (int i = pos[finish]; i < cnt; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
