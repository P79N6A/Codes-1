#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 111;
typedef long long ll;

int n, m, k, len;
int pre[MAXN];
bool flag;
bool vis[MAXN];
vector<int> e[MAXN];

void dfs(int node, int cnt, int f)
{
    if (!flag)
    {
        pre[len++] = node;
        for (int i = 0; i < e[node].size(); ++i)
        {
            int& t = e[node][i];
            if (t == f && cnt >= k + 1)
            {
                flag = 1;
                return;
            }
            if (t == f)
                return;
            if (!vis[t])
            {
                vis[t] = 1;
                dfs(t, cnt + 1, f);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!flag)
        {
            memset(vis, 0, sizeof vis);
            len = 0;
            vis[i] = 1;
            dfs(i, 1, i);
        }
    }
    printf("%d\n", len);
    for (int i = 0; i < len - 1; ++i)
        printf("%d ", pre[i]);
    printf("%d\n", pre[len - 1]);
    return 0;
}