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
const int MAXN = 111;

vector<int> G[MAXN];
set<int> cut;
int rt = 1, dfn[MAXN], low[MAXN], cnt;

void tarjan(int fa, int u)
{
    int child = 0;
    dfn[u] = low[u] = ++cnt;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if (!dfn[v])
        {
            ++child; tarjan(u, v);
            low[u] = min(low[u], low[v]);
            if (u == rt && child > 1) cut.insert(u);
            if (u != rt && low[v] >= dfn[u]) cut.insert(u);
        }
        else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, u, v;
    string s;
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; ++i) G[i].clear(), low[i] = dfn[i] = 0;
        while (getline(cin, s))
        {
            int cnt = 0;
            stringstream ss(s);
            while (ss >> v)
            {
                if (!cnt) u = v;
                else G[u].push_back(v), G[v].push_back(u);
                if (v == 0) goto ed;
                cnt = 1;
            }
        }
ed:
        cut.clear(); cnt = 0;
        tarjan(-1, 1);

        cout << cut.size() << '\n';
    }
    return 0;
}
