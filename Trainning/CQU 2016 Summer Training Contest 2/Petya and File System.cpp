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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e4 + 111;

map<string, int> mp[MAXN];
vector<pii> G[MAXN];
int dp1[MAXN], dp2[MAXN];
bool vis[MAXN];
int indx = 0;

int getid(int u, string s) {
    int ret = mp[u][s];
    if (!ret) ret = mp[u][s] = ++indx;
    return ret;
}

void dfs(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i].first;
        dfs(v);
        dp1[u] += dp1[v] + (G[u][i].second == 0);
        dp2[u] += dp2[v] + (G[u][i].second == 1);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s, x;
    while (cin >> s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ':' || s[i] == '\\') s[i] = ' ';
        }
        stringstream ss(s);
        ss >> x;
        int id = getid(0, x);
        int pre = id;
        if (!vis[id]) {
            G[0].push_back(make_pair(id, 0));
            vis[id] = 1;
        }
        while (ss >> x) {
            id = getid(pre, x);
            int sta = (x.find('.') != -1);
            if (!vis[id]) {
                G[pre].push_back(make_pair(id, sta));
                vis[id] = 1;
            }
            pre = id;
        }
    }
    dfs(0);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < G[0].size(); ++i) {
        int u = G[0][i].first;
        for (int j = 0; j < G[u].size(); ++j) {
            int v = G[u][j].first;
            ans1 = max(ans1, dp1[v]);
            ans2 = max(ans2, dp2[v]);
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}
