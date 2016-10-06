#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 50;

char mp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
int l, r, c;
int dz[]={-1,1,0,0,0,0};
int dx[]={0,0,0,0,-1,1};
int dy[]={0,0,-1,1,0,0};

struct Node{
    int z, x, y, dis;
    Node(int a, int b, int c, int d): z(a), x(b), y(c), dis(d){}
};

int main() {
    ios_base::sync_with_stdio(0);
    while (cin >> l >> r >> c && l + r + c)
    {
        int ans = -1;
        memset(vis, 0, sizeof vis);
        queue<Node> q;
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < r; ++j)
                for (int k = 0; k < c; ++k)
                {
                    //cout << i << j << k << endl;
                    cin >> mp[i][j][k];
                    if (mp[i][j][k] == 'S')
                    {
                        q.push(Node(i, j, k, 0));
                        vis[i][j][k] = 1;
                    }
                }
        while (!q.empty())
        {
            Node e = q.front(); q.pop();
            for (int i = 0; i < 6; ++i)
            {
                int nz = e.z + dz[i], nx = e.x + dx[i], ny = e.y + dy[i], ndis = e.dis + 1;
                if (0 <= nz && nz < l && 0 <= nx && nx < r && 0 <= ny && ny < c && mp[nz][nx][ny] != '#' && !vis[nz][nx][ny])
                {
                    if (mp[nz][nx][ny] == 'E')
                        ans = ndis;
                    vis[nz][nx][ny] = 1;
                    q.push(Node(nz, nx, ny, ndis));
                }
            }
        }
        if (ans == -1)
            cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
    return 0;
}