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
const int MAXN = 61;

vector<int> G[MAXN];
int vis[MAXN];

int bfs(int s)
{
    int ret = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size())
    {
        int cur = q.front(); q.pop();
        for (int i = 0; i < G[cur].size(); ++i)
        {
            int v = G[cur][i];
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
                ++ret;
            }
        }
    }
    return ret;
}

int main()
{
    int n, m, cnt = 0, x, y;
    scanf("%d%d", &n, &m);
    while (m --)
    {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) if (!vis[i])
        cnt += bfs(i);

    printf("%I64d\n", (ll)pow(2, cnt));
    return 0;
}
