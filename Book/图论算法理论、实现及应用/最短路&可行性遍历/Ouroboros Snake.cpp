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

struct Edge {
    int to, nxt;
}edge[MAXN];
bool vis[MAXN];
int head[MAXN], tol;
int ans[16][MAXN], n, k, up;
int len[16];

void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

bool dfs(int u) {
    //pr(u)
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        if (!vis[i]) {
            vis[i] = 1;
            //pr(edge[i].to)
            dfs(edge[i].to % up);
            ans[n][len[n]++] = edge[i].to;
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &k) && (n | k)) {
        if (len[n]) printf("%d\n", ans[n][len[n] - 1 - k]);
        else {
            memset(head, -1, sizeof head);
            memset(vis, 0, sizeof vis);
            tol = 0;
            up = 1 << (n - 1);
            for (int i = 0; i < up; ++i) {
                addedge(i, (i << 1) + 1);
                addedge(i, i << 1);
            }
            dfs(0);
            //pr(len[n])
            printf("%d\n", ans[n][len[n] - 1 - k]);
        }
    }
    return 0;
}
