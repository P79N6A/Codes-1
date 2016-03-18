#include<cstdio>
#include<iostream>
#include<queue>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

struct Node{
    int v, id;
    ll w;
    Node(int _v, ll _w, int _id): v(_v), w(_w), id(_id) {}
};

int dep[MAXN], fa[MAXN], par[MAXN], point[MAXN]; // point:������Ӧ�ı�id
ll val[2 * MAXN];
vector<Node> G[MAXN];

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void dfs(int u, int p, int d)
{
    dep[u] = d;
    fa[u] = p;
    for (int i = 0; i < G[u].size(); ++i)
    {
        Node &e = G[u][i];
        if (e.v != p)
        {
            val[e.v] = e.w; // ��������Ӧ��Ȩֵת��Ϊ��������Ϊ��β�ı߶�Ӧ��Ȩֵ����¼
            point[e.id] = e.v; // ��id�����ҵ�
            dfs(e.v, u, d + 1);
        }
    }
}

ll lca(int u, int v, ll w)
{
    u = find(u), v = find(v);
    while (u != v) // ÿ�ν��ϵ͵Ľ���������������ϳ�
    {
        if (dep[u] < dep[v]) swap(u, v);
        w /= val[u]; u = find(fa[u]);
        if (w == 0) return 0;
    }
    return w;
}

void update(int u) // ����ĵ�ȨֵΪһ����ô������������ָ�����ĸ��׽��
{
    par[u] = fa[u];
}

int main()
{
    int n, m, u, v, op;
    ll w;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) G[i].clear(), par[i] = i;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d%I64d", &u, &v, &w);
        G[u].push_back(Node(v, w, i));
        G[v].push_back(Node(u, w, i));
    }

    dfs(1, -1, 0);

    for (int i = 2; i <= n; ++i) if (val[i] == 1) update(i);

    int a, b, p;
    ll y, c;
    while (m --)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%I64d", &a, &b, &y);
            printf("%I64d\n", lca(a, b, y));
        }
        else
        {
            scanf("%d%I64d", &p, &c);
            int v = point[p]; val[v] = c;
            if (c == 1) update(v);
        }
    }
    return 0;
}
