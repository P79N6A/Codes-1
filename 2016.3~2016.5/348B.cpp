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
const int MAXN = 1e5 + 111;

string s;
int num[MAXN], n;
bool vis[MAXN];

bool dfs(int x) {
    if (x < 0 || x >= n) return 1;
    vis[x] = 1;
    if (s[x] == '<') {
        if (x - num[x] >= 0 && vis[x - num[x]]) return 0;
        return dfs(x - num[x]);
    }
    if (x + num[x] < n && vis[x + num[x]]) return 0;
    return dfs(x + num[x]);
}

int main()
{
    while (cin >> n) {
        cin >> s;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i) cin >> num[i];
        if (dfs(0)) cout << "FINITE\n";
        else cout << "INFINITE\n";
    }
    return 0;
}
