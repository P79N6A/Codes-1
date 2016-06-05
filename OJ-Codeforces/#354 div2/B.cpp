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
const int MAXN = 1e6 + 111;

double a[20][20];
int n, t;

void dfs(int i, int j, double w) {
    if (i > n) return;
    if (a[i][j] == 1) {
        dfs(i + 1, j, w / 2);
        dfs(i + 1, j + 1, w / 2);
    }
    else a[i][j] += w;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> n >> t) {
        memset(a, 0, sizeof a);
        for (int i = 1; i <= t; ++i) {
            dfs(1, 1, 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (a[i][j] == 1) ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
