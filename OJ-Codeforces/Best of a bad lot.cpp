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
const int MAXN = 411;

map<string, int> mp;
int indx, pos[MAXN];
vector<int> G[MAXN], T[MAXN];

int id(string &s) {
    if (mp.count(s)) return mp[s];
    return mp[s] = ++indx;
}

int col[MAXN];
vector<int> ans;
void bfs(int x) {
    vector<int> save[2];
    save[0].push_back(x);
    col[x] = 0;
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (col[v] == -1) {
                col[v] = !col[u];
                save[col[v]].push_back(v);
                q.push(v);
            }
        }
    }
    int w = save[0].size() < save[1].size() ? 0 : 1;
    for (int i = 0; i < save[w].size(); ++i) {
        ans.push_back(save[w][i]);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, x; cin >> n;
    string s;
    // 如果x看到y了，但是y却在其它地方，那么x和y矛盾
    for (int i = 1; i <= n; ++i) {
        cin >> s >> m;
        pos[i] = id(s);
        while (m --) {
            cin >> x;
            T[x].push_back(i);
        }
        T[i].push_back(i);
    }
    memset(col, -1, sizeof col);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < T[i].size(); ++j) {
            for (int k = j + 1; k < T[i].size(); ++k) {
                int u = T[i][j], v = T[i][k];
                if (pos[u] != pos[v]) {
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (col[i] == -1) bfs(i);
    }
    if (ans.size() == 0) ans.push_back(1);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    return 0;
}
