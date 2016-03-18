#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

vector<int> G[MAXN];
int p[MAXN], in[MAXN], a[MAXN], b[MAXN];
char cmp[2 * MAXN];

int find(int x)
{
    return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) p[x] = y;
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; ++i) G[i].clear(), p[i] = i, in[i] = 0;
        int sum = n;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %c %d", &a[i], &cmp[i], &b[i]);
            if (cmp[i] == '=') unite(a[i], b[i]), --sum; // 相等的看作一个整体
        }
        bool conf = 0, uncer = 0;
        for (int i = 0; i < m; ++i)
        {
            if (cmp[i] == '=') continue;
            int x = find(a[i]), y = find(b[i]);
            if (x == y) conf = 1; // 等级相同却又存在绝对大小关系，矛盾
            if (cmp[i] == '>') G[x].push_back(y), ++in[y];
            else G[y].push_back(x), ++in[x];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            int cur = find(i);
            if (!in[cur] && p[cur] == i) q.push(cur);
        }

        while (q.size())
        {
            int cur = q.front(); q.pop(); --sum;
            if (q.size()) uncer = 1;  // 多个点可以操作，无法确定哪一个
            for (int i = 0; i < G[cur].size(); ++i)
            {
                int v = G[cur][i];
                if (--in[v] == 0) q.push(v);
            }
        }

        if(sum > 0 || conf) printf("CONFLICT\n");
        else if(uncer) printf("UNCERTAIN\n");
        else printf("OK\n");
    }
    return 0;
}
