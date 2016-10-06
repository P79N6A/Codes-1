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

const ll INF = 0x7f7f7f7f7f7f7f7f;
const int MAXN = 1320;
const int MAXNL = 27080;

int ecnt, n, anslove;
int head[MAXNL], to[MAXNL], from[MAXNL];
int id[MAXNL], nxt[MAXNL];
ll val[MAXNL], ans, dis[MAXN];

void add_edge(int u, int v, ll w, int _id)
{
    to[ecnt] = v;
    val[ecnt] = w;
    id[ecnt] = _id;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

struct Node{
    int node, nxid, love;
    Node(int _node, int _id, int _love): node(_node), nxid(_id), love(_love){}
    Node()
    {
        node = 0, nxid = 0, love = 0;
    }
};

void spfa(int s)
{
    memset(dis, 0x7f, sizeof(ll) * (n + 2));
    Node sta[MAXN];
    int top = 0;
    sta[top++] = Node(s, 0, 0);
    dis[s] = 0;
    while (top)
    {
        Node cur = sta[--top];
        for (int i = head[cur.node]; ~i; i = nxt[i])
        {
            int v = to[i];
            if (id[i] != cur.nxid) continue;
            if (dis[v] > dis[cur.node] + val[i])
            {
                dis[v] = dis[cur.node] + val[i];
                if (cur.nxid == 3) ++cur.love;
                if (v == n) anslove = max(anslove, cur.love);
                sta[top++] = Node(v, (cur.nxid + 1) % 4, cur.love);
                if (cur.nxid == 3) --cur.love;
            }
            else if (dis[v] == dis[cur.node] + val[i])
            {
                if (cur.nxid == 3)
                {
                    ++cur.love;
                    sta[top++] = Node(v, (cur.nxid + 1) % 4, cur.love);
                    --cur.love;
                }
            }
        }
        if (dis[s] == 0) dis[s] == INF;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, m, u, v, w, _id, kase = 0; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(int) * (n + 2));
        ecnt = 0; ans = INF; anslove = 0;
        char mark[2];
        while (m --)
        {
            scanf("%d %d %d %s", &u, &v, &w, mark);
            if (mark[0] == 'L') _id = 0;
            else if (mark[0] == 'O') _id = 1;
            else if (mark[0] == 'V') _id = 2;
            else _id = 3;
            add_edge(u, v, w, _id);
            add_edge(v, u, w, _id);
        }

        spfa(1);

        printf("Case %d: ", ++kase);
        if (dis[n] == INF || anslove == 0) printf("Binbin you disappoint Sangsang again, damn it!\n");
        else
            printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n", dis[n], anslove);
    }
    return 0;
}
