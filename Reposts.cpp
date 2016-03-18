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

const int INF = 0x7f7f7f7f;
const int MAXN = 211;

vector<int> G[MAXN];
map<string, int> id;
int cnt = 0;

void change(string &t) {
    for (int i = 0; i < t.size(); ++i) {
        t[i] = tolower(t[i]);
    }
}

int getid(string &t) {
    int ret = id[t];
    if (ret) return ret;
    return id[t] = ++cnt;
}

int ans = 0;

void dfs(int u, int dep) {
    if (G[u].size() == 0) {
        ans = max(ans, dep);
        return;
    }

    for (int i = 0; i < G[u].size(); ++i) {
        dfs(G[u][i], dep + 1);
    }
}

int main()
{
    int n;
    string a, b, c;
    cin >> n;
    while (n --) {
        cin >> a >> b >> c;
        change(a); change(c);
        int u = getid(c), v = getid(a);
        //cout << u << "->" << v << endl;
        G[u].push_back(v);
    }

    dfs(1, 1);

    cout << ans << '\n';
    return 0;
}
