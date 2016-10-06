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

int a[MAXN], b[MAXN];

int dp[1000][1000];
int n;

bool dfs(int x, int y, int d) {
    int &ret = dp[x + 200][y + 200];
    if (ret != -1) return ret;
    for (int i = 0; i < n; ++i) {
        int dx = x + a[i], dy = y + b[i];
        if (dx * dx + dy * dy > d) continue;
        if (!dfs(dx, dy, d)) {
            return ret = 1;
        }
    }
    return ret = 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x, y, d;
    cin >> x >> y >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    memset(dp, -1, sizeof dp);
    if (dfs(x, y, d * d)) cout << "Anton\n";
    else cout << "Dasha\n";
    return 0;
}
