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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 111;

bool vis[5][5][5][5][5][5][5][5][5];
int dp[10][10][10][10];
int dir[2][4] = {1, -1, 0, 0, 0, 0, 1, -1};
struct S {
    int mp[3][3];
    int step;
    int num[5];
    S(){
        memset(mp, 0, sizeof mp);
        step = 0;
        memset(num, 0, sizeof num);
    }
};

void bfs() {
    queue<S> q;
    S fst;
    q.push(fst);
    vis[0][0][0][0][0][0][0][0][0] = 1;
    while (q.size()) {
        S u = q.front(); q.pop();
        dp[u.num[1]][u.num[2]][u.num[3]][u.num[4]] = min(u.step, dp[u.num[1]][u.num[2]][u.num[3]][u.num[4]]);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int org = u.mp[i][j];

                // blue
                if (u.mp[i][j] != 1) {
                    ++u.step;
                    ++u.num[1];
                    --u.num[org];
                    u.mp[i][j] = 1;
                    if (!vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]]) {
                        vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]] = 1;
                        q.push(u);
                    }
                    u.mp[i][j] = org;
                    ++u.num[org];
                    --u.num[1];
                    --u.step;
                }

                // red
                int num1 = 0, num2 = 0, num3 = 0;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dir[0][k], ny = j + dir[1][k];
                    if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                        if (u.mp[nx][ny] == 1)
                            ++num1;
                    }
                }
                if (num1 && u.mp[i][j] != 2) {
                    ++u.step;
                    ++u.num[2];
                    --u.num[org];
                    u.mp[i][j] = 2;
                    if (!vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]]) {
                        vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]] = 1;
                        q.push(u);
                    }
                    u.mp[i][j] = org;
                    ++u.num[org];
                    --u.num[2];
                    --u.step;
                }

                // green
                num1 = 0, num2 = 0, num3 = 0;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dir[0][k], ny = j + dir[1][k];
                    if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                        if (u.mp[nx][ny] == 1)
                            ++num1;
                        if (u.mp[nx][ny] == 2)
                            ++num2;
                    }
                }
                if (num1 && num2 && u.mp[i][j] != 3) {
                    ++u.step;
                    ++u.num[3];
                    --u.num[org];
                    u.mp[i][j] = 3;
                    if (!vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]]) {
                        vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]] = 1;
                        q.push(u);
                    }
                    u.mp[i][j] = org;
                    ++u.num[org];
                    --u.num[3];
                    --u.step;
                }

                // yellow
                num1 = 0, num2 = 0, num3 = 0;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dir[0][k], ny = j + dir[1][k];
                    if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                        if (u.mp[nx][ny] == 1)
                            ++num1;
                        if (u.mp[nx][ny] == 2)
                            ++num2;
                        if (u.mp[nx][ny] == 3)
                            ++num3;
                    }
                }
                if (num1 && num2 && num3 && u.mp[i][j] != 4) {
                    ++u.step;
                    ++u.num[4];
                    --u.num[org];
                    u.mp[i][j] = 4;
                    if (!vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]]) {
                        vis[u.mp[0][0]][u.mp[0][1]][u.mp[0][2]][u.mp[1][0]][u.mp[1][1]][u.mp[1][2]][u.mp[2][0]][u.mp[2][1]][u.mp[2][2]] = 1;
                        q.push(u);
                    }
                    u.mp[i][j] = org;
                    ++u.num[org];
                    --u.num[4];
                    --u.step;
                }
            }
        }
    }
}

void init() {
    memset(vis, 0, sizeof vis);
    memset(dp, 0x3f, sizeof dp);
    bfs();
}

int main()
{
    init();
    int b, r, g, y, w, kase = 0;
    while (~scanf("%d", &b) && b) {
        printf("Case %d: ", ++kase);
        scanf("%d%d%d%d", &r, &g, &y, &w);
        int ans = INF;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 10; ++l)
                        if (b*i + r*j + g*k + l*y >= w) {
                            ans = min(ans, dp[i][j][k][l]);
                        }
                }
            }
        }
        if (ans == INF) printf("Impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}
