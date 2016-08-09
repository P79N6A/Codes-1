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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 21;

int len;
struct Snake {
    short x[10], y[10], step;
    bool operator < (const Snake&t) const {
        for (int i = 1; i <= len; ++i) {
            if (x[i] != t.x[i]) return x[i] < t.x[i];
            if (y[i] != t.y[i]) return y[i] < t.y[i];
        }
        return 0;
    }
};
char mp[MAXN][MAXN];
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int n, m;

bool check(Snake&t, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#') return 1;
    for (int i = 2; i < len; ++i) {
        if (x == t.x[i] && y == t.y[i]) return 1;
    }
    return 0;
}

Snake moveto(Snake&t, int x, int y) {
    Snake ret;
    for (int i = 2; i <= len; ++i) {
        ret.x[i] = t.x[i - 1];
        ret.y[i] = t.y[i - 1];
    }
    ret.x[1] = x;
    ret.y[1] = y;
    ret.step = t.step + 1;
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    Snake st;
    for (int i = 0; i < n; ++i) {
        scanf("%s", mp[i]);
        for (int j = 0; j < m; ++j) {
            if (isdigit(mp[i][j])) {
                int num = mp[i][j] - '0';
                len = max(len, num);
                st.x[num] = i, st.y[num] = j;
            }
        }
    }
    int ans = -1;
    st.step = 0;
    queue<Snake> q;
    map<Snake, bool> vis;
    q.push(st);
    vis[st] = 1;
    while (q.size()) {
        Snake cur = q.front(); q.pop();
        int x = cur.x[1], y = cur.y[1];
        if (mp[x][y] == '@') {
            ans = cur.step;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            //printf("%d %d\n", nx, ny);
            if (check(cur, nx, ny)) continue;
            Snake nxt = moveto(cur, nx, ny);
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
