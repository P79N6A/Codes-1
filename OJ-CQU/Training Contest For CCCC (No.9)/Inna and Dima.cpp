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
const int MAXN = 1111;

char mp[MAXN][MAXN];
bool flag[MAXN][MAXN];
int dp[MAXN][MAXN], n, m;
int dir[2][4] = {0, -1, 0, 1, 1, 0, -1, 0};
int nxt[26];

int dfs(int x, int y) {
//    printf("%d %d -> \n", x, y);
    if (flag[x][y]) return -1;
    int &ret = dp[x][y];
    if (ret != -1) {
        return ret;
    }
    flag[x][y] = 1;
    int u = mp[x][y] - 'A';
    int mx = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[0][i], ny = y + dir[1][i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (mp[nx][ny] == nxt[u]) {
                int temp = dfs(nx, ny);
                if (temp == -1) {
                    flag[x][y] = 0;
                    return temp;
                }
                mx = max(temp, mx);
            }
        }
    }
    flag[x][y] = 0;
    ret = (mp[x][y] == 'A') + mx;
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mp[i]);
    }
    nxt['D' - 'A'] = 'I';
    nxt['I' - 'A'] = 'M';
    nxt['M' - 'A'] = 'A';
    nxt['A' - 'A'] = 'D';
    memset(dp, -1, sizeof dp);
    int ans = 0;
    bool ok = 1;
    int cnt = 1;
    for (int i = 0; i < n && flag; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == 'D') {
                int temp = dfs(i, j);
//                printf("%d %d %d\n", i, j, temp);
                if (temp == -1) {
//                    printf("%d %d\n", i, j);
                    ok = 0;
                    break;
                }
                ans = max(ans, temp);
            }
        }
    }
    if (!ok) printf("Poor Inna!\n");
    else if (!ans) printf("Poor Dima!\n");
    else printf("%d\n", ans);
    return 0;
}
