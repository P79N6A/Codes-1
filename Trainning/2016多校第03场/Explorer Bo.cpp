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

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 111;

struct Edge {
    int to, nxt;
}edge[MAXN << 1];
int head[MAXN], tol;
// dp[i][0]:�������һ�������ڸ�������    dp[i][1]:�������һ�����ڸ�������
int dp[MAXN][2], son[MAXN], deg[MAXN];

inline void addedge(int u, int v) {
    edge[tol].to = v;
    edge[tol].nxt = head[u];
    head[u] = tol++;
}

inline void init(int n) {
    tol = 0;
    for (int i = 1; i <= n; ++i) {
        head[i] = -1, deg[i] = 0;
        dp[i][1] = INF;
    }
}

void dfs(int u, int f) {
    dp[u][0] = 0;
    son[u] = 0;
    int child = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs(v, u);
        ++child;
        son[u] += son[v];
        // ż�����ӽڵ�����϶��ó�ȥ������ڲ������Ļ�����û�о�����ȥ�ı���
        dp[u][0] += dp[v][0] + (son[v] & 1 ? 1 : 2);
    }
    if (!son[u]) son[u] = 1;
    // ö�����п��ܳ��ֶ�����ĵص�
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        // ��������������1�Ҷ��Ӹ���Ϊ1�ų�ʼ�����ſ��ܳ�Ϊ��������ڵĵط���
        if (child > 1 && son[v] == 1) dp[u][1] = min(dp[u][1], dp[u][0]);
        if (dp[v][1] == INF) continue;
        int add = dp[u][0] - dp[v][0] + (son[v] & 1 ? 1 : -1);
        dp[u][1] = min(dp[u][1], add + dp[v][1]);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, u, v; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        init(n);
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
            ++deg[u], ++deg[v];
        }
        int cnt = 0, rt = 1;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] != 1) rt = i;
            else ++cnt;
        }
        dfs(rt, -1);
        if (cnt & 1) printf("%d\n", dp[rt][1]);
        else printf("%d\n", dp[rt][0]);
    }
    return 0;
}
