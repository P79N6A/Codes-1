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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 311;

struct P {
    int x, y, dis;
    P(int a, int b, int c): x(a), y(b), dis(c) {};
};
int mp[311][311];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int vis[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, p;
    while (~scanf("%d%d%d", &n, &m, &p)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &mp[i][j]);
                vis[i][j] = 0;
            }
        }
        int ans = 0;
        queue<P> q;
        q.push(P(0, 0, 0));
        int des = min(2, p);
        vis[0][0] = des;
        while (q.size()) {
            P cur = q.front(); q.pop();
            if (des == p && mp[cur.x][cur.y] == p) {
                    ans += cur.dis;
                    break;
            }
            if (mp[cur.x][cur.y] == des) {
                ans += cur.dis;
                //pr("=====")pr(des)pr(ans)
                ++des;
                while (q.size()) q.pop();
                q.push(P(cur.x, cur.y, 0));
                vis[cur.x][cur.y] = des;
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && vis[nx][ny] != des) {
                    vis[nx][ny] = des;
                    q.push(P(nx, ny, cur.dis + 1));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
