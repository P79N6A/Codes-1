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
const int MAXN = 111;

int x[MAXN], y[MAXN];
bool ok[MAXN];
int ans = 0, n;

void dfs(int u) {
    ok[u] = 1;
    for (int i = 0; i < n; ++i) {
        if (ok[i]) continue;
        if (x[i] == x[u] || y[i] == y[u])
            dfs(i);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!ok[i]) {
            ++ans;
            dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}
