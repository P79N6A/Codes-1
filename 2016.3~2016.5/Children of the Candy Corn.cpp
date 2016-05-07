#include<stdio.h>
#include<string.h>

char mp[101][101];
int vis[101][101];
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, 1, -1}};
int ax[4] = {-1, 0, 1, 0};
int ay[4] = {0, 1, 0, -1};
int w, h, sx, sy;

struct P {
    int x, y, dis;
}q[10000];

// st记录走的方向:0~3分别代表：↑→↓←
int dfsl(int x, int y, int st, int dis) {
    if (mp[x][y] == 'E') return dis;
    int nx = x + ax[st], ny = y + ay[st];
    //printf("(%d,%d) -> (%d,%d) st == %d, dis == %d\n", x, y, nx, ny, st, dis);
    //system("pause");
    if (0 < nx && nx <= h && 0 < ny && ny <= w) {
        if (st == 0) {
            if (mp[x][y - 1] == '#' && mp[nx][ny] != '#')
                return dfsl(nx, ny, st, dis + 1);
            else if (mp[x][y - 1] == '.' || mp[x][y - 1] == 'E')
                return dfsl(x, y - 1, 3, dis + 1);
        }
        else if (st == 1) {
            if (mp[x - 1][y] == '#' && mp[nx][ny] != '#')
                return dfsl(nx, ny, st, dis + 1);
            else if (mp[x - 1][y] == '.' || mp[x - 1][y] == 'E')
                return dfsl(x - 1, y, 0, dis + 1);
        }
        else if (st == 2) {
            if (mp[x][y + 1] == '#' && mp[nx][ny] != '#')
                return dfsl(nx, ny, st, dis + 1);
            else if (mp[x][y + 1] == '.' || mp[x][y + 1] == 'E')
                return dfsl(x, y + 1, 1, dis + 1);
        }
        else {
            if (mp[x + 1][y] == '#' && mp[nx][ny] != '#')
                return dfsl(nx, ny, st, dis + 1);
            else if (mp[x + 1][y] == '.' || mp[x + 1][y] == 'E')
                return dfsl(x + 1, y, 2, dis + 1);
        }
    }
    return dfsl(x, y, (st + 1) % 4, dis);
}

int dfsr(int x, int y, int st, int dis) {
    if (mp[x][y] == 'E') return dis;
    int nx = x + ax[st], ny = y + ay[st];
    //printf("(%d,%d) -> (%d,%d) st == %d, dis == %d\n", x, y, nx, ny, st, dis);
    //system("pause");
    if (0 < nx && nx <= h && 0 < ny && ny <= w) {
        if (st == 0) {
            if (mp[x][y + 1] == '#' && mp[nx][ny] != '#')
                return dfsr(nx, ny, st, dis + 1);
            else if (mp[x][y + 1] == '.' || mp[x][y + 1] == 'E')
                return dfsr(x, y + 1, 1, dis + 1);
        }
        else if (st == 1) {
            if (mp[x + 1][y] == '#' && mp[nx][ny] != '#')
                return dfsr(nx, ny, st, dis + 1);
            else if (mp[x + 1][y] == '.' || mp[x + 1][y] == 'E')
                return dfsr(x + 1, y, 2, dis + 1);
        }
        else if (st == 2) {
            if (mp[x][y - 1] == '#' && mp[nx][ny] != '#')
                return dfsr(nx, ny, st, dis + 1);
            else if (mp[x][y - 1] == '.' || mp[x][y - 1] == 'E')
                return dfsr(x, y - 1, 3, dis + 1);
        }
        else {
            if (mp[x - 1][y] == '#' && mp[nx][ny] != '#')
                return dfsr(nx, ny, st, dis + 1);
            else if (mp[x - 1][y] == '.' || mp[x - 1][y] == 'E')
                return dfsr(x - 1, y, 0, dis + 1);
        }
    }
    return dfsr(x, y, (st - 1 + 4) % 4, dis);
}

int bfs() {
    int l = 0, r = 0;
    memset(vis, 0, sizeof vis);
    vis[sx][sy] = 1;
    q[r].x = sx;
    q[r].y = sy;
    q[r++].dis = 1;
    while (l < r) {
        struct P cur = q[l++];
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dir[0][i], ny = cur.y + dir[1][i];
            if (0 < nx && nx <= h && 0 < ny && ny <= w && mp[nx][ny] != '#' && !vis[nx][ny]) {
                if (mp[nx][ny] == 'E') {
                    return cur.dis + 1;
                }
                q[r].x = nx, q[r].y = ny, q[r++].dis = cur.dis + 1;
                vis[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    int n; scanf("%d", &n);
    while (n --) {
        scanf("%d%d", &w, &h);
        for (int i = 1; i <= h; ++i) {
            scanf("%s", mp[i] + 1);
            for (int j = 1; j <= w; ++j) {
                if (mp[i][j] == 'S') {
                    sx = i, sy = j;
                }
            }
        }

        int ans1, ans2, ans3;
        ans1 = dfsl(sx, sy, 0, 1);
        ans2 = dfsr(sx, sy, 0, 1);
        ans3 = bfs();

        printf("%d %d %d\n", ans1, ans2, ans3);
    }
    return 0;
}
