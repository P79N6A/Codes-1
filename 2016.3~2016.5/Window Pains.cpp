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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

vector<int> G[10];
int mp[10][10];
int vis[10];

bool dfs(int u) {
    vis[u] = -1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (vis[v] == -1) return 0;
        if (!vis[v] && !dfs(v)) return 0;
    }
    vis[u] = 1;
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s;
    ios_base::sync_with_stdio(0);
    while (cin >> s && s.length() < 6) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> mp[i][j];
            }
        }
        cin >> s;
        for (int i = 1; i <= 9; ++i) G[i].clear();

        for (int i = 1; i <= 9; ++i) {
            int t = i - 1;
            for (int j = t / 3; j <= t / 3 + 1; ++j) {
                for (int k = t % 3; k <= t % 3 + 1; ++k) {
                    if (mp[j][k] != i) {
                        G[mp[j][k]].push_back(i);
                    }
                }
            }
        }

        memset(vis, 0, sizeof vis);
        bool flag = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!vis[i] && !dfs(i)) {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "THESE WINDOWS ARE BROKEN\n";
        else cout << "THESE WINDOWS ARE CLEAN\n";
    }
    return 0;
}
