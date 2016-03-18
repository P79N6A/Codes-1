#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1511;
const ll INF = 9223372036854775807;
struct N{
    int v, w, id;
    N(int vv, int ww, int iid):v(vv), w(ww), id(iid){}
};
int num[MAXN][4], n;
ll dis[MAXN][4];
bool in[MAXN][4];
vector<N> mp[MAXN];

int getid(char c)
{
    switch(c)
    {
        case 'L': return 0;
        case 'O': return 1;
        case 'V': return 2;
        case 'E': return 3;
    }
}

void spfa(int s)
{
    for (int i = 0; i <= n; ++i) for (int j = 0; j < 4; ++j)
    {
        dis[i][j] = INF;
        in[i][j] = 0;
        num[i][j] = 0;
    }
    dis[s][3] = 0;
    num[s][3] = 0;
    in[s][3] = 1;
    queue<pii> Q;
    Q.push(pii(s, 3));
    while (Q.size())
    {
        pii cur = Q.front(); Q.pop();
        int u = cur.first, id = cur.second;
        in[u][id] = 0;
        for (int i = 0; i < mp[u].size(); ++i)
        {
            N &e = mp[u][i];
            int v = e.v, w = e.w, nid = e.id;
            if ((id + 1) % 4 == nid)
            {
                if (dis[v][nid] > dis[u][id] + w)
                {
                    dis[v][nid] = dis[u][id] + w;
                    num[v][nid] = num[u][id];
                    if (nid == 3) ++num[v][nid];
                    if (!in[v][nid]) {in[v][nid] = 1; Q.push(pii(v, nid));}
                }
                else if (dis[v][nid] == dis[u][id] + w && num[v][nid] <= num[u][id])
                {
                    num[v][nid] = num[u][id];
                    if (nid == 3) ++num[v][nid];
                    if (!in[v][nid]) {in[v][nid] = 1; Q.push(pii(v, nid));}
                }
            }
        }
        //关于特判：因为默认以dis[1][3]作为起始点，但最终又要到达1,3所以要更新成无穷
        if (n == 1 && num[1][3] == 0)
            dis[1][3] = INF;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, m; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; ++i) mp[i].clear();
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            char c;
            scanf("%d %d %d %c", &u, &v, &w, &c);
            int id = getid(c);
            mp[u].push_back(N(v,w,id));
            mp[v].push_back(N(u,w,id));
        }
        spfa(1);
        printf("Case %d: ", kase);
        if (num[n][3] == 0 || dis[n][3] == INF)
            printf("Binbin you disappoint Sangsang again, damn it!\n");
        else
            printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n", dis[n][3], num[n][3]);
    }
    return 0;
}
