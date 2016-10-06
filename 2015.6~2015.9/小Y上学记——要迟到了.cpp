#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x7f7f7f7f, MAXN = 1111;
struct N{
    int to, next, val;
}edge[MAXN*MAXN];
int n, m, k, d[20][MAXN], cnt, head[MAXN];
bool in[20][MAXN];

void add_edge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].val = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void init()
{
    cnt = 0;
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (u == v) continue;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
}

void spfa(int s)
{
    memset(d, 0x7f, sizeof d);
    memset(in, 0, sizeof in);
    d[0][s] = 0;
    queue<pii> q;
    q.push(pii(0, s));
    in[0][s] = 1;
    while (q.size())
    {
        pii now = q.front(); q.pop();
        int cei = now.first, e = now.second; //cei:使用了几次能力。当前层数
        in[cei][e] = 0;
        for (int i = head[e]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (d[cei][v] > d[cei][e] + edge[i].val) //不使用超能力
            {
                d[cei][v] = d[cei][e] + edge[i].val;
                if (!in[cei][v])
                {
                    in[cei][v] = 1;
                    q.push(pii(cei, v));
                }
            }
            if (cei < k && d[cei + 1][v] > d[cei][e]) //使用
            {
                d[cei + 1][v] = d[cei][e];
                if (!in[cei + 1][v])
                {
                    in[cei + 1][v] = 1;
                    q.push(pii(cei + 1, v));
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        init();
        spfa(1);
        printf("%d\n", d[k][n]);
    }
    return 0;
}
