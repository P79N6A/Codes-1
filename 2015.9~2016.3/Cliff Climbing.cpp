#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 100;

struct Node{
    int h, w, sta;
    Node(int _h, int _w, int _sta):h(_h), w(_w), sta(_sta){}
};
char mp[MAXN][MAXN][2];
int dis[MAXN][MAXN][2];
int dir[2][9][2] = {{-1, -2, -1, -1, -2, -1, -1, 0, -2, 0, -3, 0, -1, 1, -2, 1, -1, 2},
                    {1, -2, 1, -1, 2, -1, 1, 0, 2, 0, 3, 0, 1, 1, 2, 1, 1, 2}};



int main()
{
    int w, h;
    while (~scanf("%d%d", &w, &h) && (w | h))
    {
        queue<Node> q;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
            {
                dis[i][j][0] = dis[i][j][1] = INF;
                scanf("%s", mp[i][j]);
                if (mp[i][j][0] == 'S')
                {
                    q.push(Node(i, j, 0)); q.push(Node(i, j, 1));
                    dis[i][j][0] = dis[i][j][1] = 0;
                }
            }

        int ans = INF;
        while (q.size())
        {
            Node cur = q.front(); q.pop();
            int nx, ny, sta = cur.sta;
            for (int i = 0; i < 9; ++i)
            {
                nx = cur.h + dir[sta][i][1], ny = cur.w + dir[sta][i][0];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && mp[nx][ny][0] != 'X')
                {
                    int val = 0;
                    if (mp[nx][ny][0] != 'T') val = mp[nx][ny][0] - '0';
                    if (dis[nx][ny][1 - sta] > dis[cur.h][cur.w][sta] + val)
                    {
                        dis[nx][ny][1 - sta] = dis[cur.h][cur.w][sta] + val;
                        q.push(Node(nx, ny, 1 - sta));
                        if (mp[nx][ny][0] == 'T') ans = min(ans, dis[nx][ny][1 - sta]);
                    }
                }
            }
        }

        if (ans == INF) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
