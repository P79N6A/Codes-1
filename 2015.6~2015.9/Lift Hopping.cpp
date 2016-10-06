#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 111;
int t[MAXN], mp[MAXN][MAXN], floors[MAXN], len, vis[MAXN], d[MAXN], n, k;
string s;

void build(int node)
{
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
        {
            int &a = floors[j], &b = floors[i];
            int dis = (a - b) * t[node];
            if (dis < mp[b][a])
                mp[a][b] = mp[b][a] = dis;
        }
}

void dijkstra()
{
    memset(vis, 0, sizeof vis);
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    for (int i = 0; i < 100; ++i)
    {
        int x, mx = INF;
        for (int y = 0; y < 100; ++y) if(!vis[y] && d[y] <= mx) mx = d[x = y];
        vis[x] = 1;
        for (int y = 0; y < 100; ++y) d[y] = min(d[y], d[x] + mp[x][y] + 60);
    }
    if (d[k] == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << max(0, d[k] - 60) << '\n';//小心目标楼层为0的情况
}

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        memset(mp, 0x3f, sizeof mp);
        for (int i = 0; i < n; ++i)
            scanf("%d", &t[i]);
        getchar();
        for (int i = 0; i < n; ++i)
        {
            len = 0;
            int x;
            getline(cin, s);
            stringstream ss(s);
            while (ss >> x)
            {
                floors[len++] = x;
            }
            build(i);
        }
        dijkstra();
    }
    return 0;
}

