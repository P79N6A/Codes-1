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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1011;

struct P {
    int id, small;
    bool operator < (const P&t)const {
        return small > t.small;
    }
};

int n, pos[MAXN], dp[MAXN];
bool mp[MAXN][MAXN];
vector<int> G[MAXN];
bool in[MAXN];
vector<P> team[2];

char line[MAXN * 2];

bool ok(int x) {
    for (int i = 0; i < team[x].size(); ++i) {
        for (int j = i + 1; j < team[x].size(); ++j) {
            P &u = team[x][i], &v = team[x][j];
            if (mp[u.id][v.id]) ++u.small;
            else ++v.small;
        }
    }
    sort(team[x].begin(), team[x].end());
    for (int i = 1; i < team[x].size(); ++i) {
        P &u = team[x][i], &v = team[x][i - 1];
        if (u.small != v.small - 1) return 0;
    }
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, x;
    while (~scanf("%d%d ", &n, &m) && (n | m)) {
        team[0].clear(), team[1].clear();
        for (int i = 1; i <= n; ++i) G[i].clear(), in[i] = 0;
        for (int i = 1; i <= n; ++i){
			gets(line);
			for (int j = 1; j <= n; ++j) {
                mp[i][j] = line[(j-1)*2] - '0';
                if (mp[i][j]) G[i].push_back(j);
			}
		}
        for (int i = 0; i < m; ++i) {
            scanf("%d", &x);
            in[x] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (in[i]) team[0].push_back(P{i, 0});
            else team[1].push_back(P{i, 0});
        }
        if (ok(0) && ok(1)) {
            int ans = 0, len = 0;
            memset(dp, 0x3f, sizeof dp);
            for (int i = 0; i < team[1].size(); ++i) {
                int cnt = 0, u = team[1][i].id;
                for (int j = 0; j < team[0].size(); ++j) {
                    int v = team[0][j].id;
                    if (mp[v][u]) ++cnt;
                    else {
                        for (j = j; j < team[0].size(); ++j) {
                            int v = team[0][j].id;
                            if (mp[v][u]) {
                                cnt = INF;
                                break;
                            }
                        }
                        break;
                    }
                }
                if (cnt != INF) pos[len++] = cnt;
            }
            for (int i = 0; i < len; ++i) {
                int x = upper_bound(dp + 1, dp + n + 1, pos[i]) - dp;
                dp[x] = pos[i];
                ans = max(ans, x);
            }
            printf("YES %d\n", ans);
        }
        else puts("NO");
    }
    return 0;
}
