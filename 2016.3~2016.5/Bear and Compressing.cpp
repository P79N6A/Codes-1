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
const int MAXN = 1e6 + 111;

vector<int> G[40];
map<string, int> id;

int ans = 0, n, q;

bool ok(string s) {
    if (s.length() == 1) {
        return s[0] == 'a';
    }
    string temp = s.substr(0,2);
    string ss = s.substr(2, s.length() - 2);
    int cur = id[temp];
    for (int i = 0; i < G[cur].size(); ++i) {
        int v = G[cur][i];
        char nx = v + 'a';
        if (ok(nx + ss)) return 1;
    }
    return 0;
}

void dfs(int x, string temp) {
    if (x == n) {
        if (ok(temp)) ++ans;
        return;
    }
    for (int i = 0; i < 6; ++i) {
        char cc = 'a' + i;
        dfs(x + 1, temp + cc);
    }
}

int main()
{

    cin >> n >> q;
    int cnt = 0;
    string a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        if (!id[a]) id[a] = ++cnt;
        G[id[a]].push_back(b[0] - 'a');
    }
    string temp;
    dfs(0, temp);
    cout << ans << '\n';
    return 0;
}
