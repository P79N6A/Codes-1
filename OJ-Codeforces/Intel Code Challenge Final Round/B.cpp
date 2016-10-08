#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 22;

int num[MAXN][MAXN], n, m;

bool dfs(int r) {
    if (r == n + 1) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                if (num[j][i] != num[1][i]) return 0;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if (num[1][i] != i) ++cnt;
        }
        if (cnt > 2) return 0;
        else return 1;
    }
    if (dfs(r + 1)) return 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            swap(num[r][i], num[r][j]);
            if (dfs(r + 1)) return 1;
            swap(num[r][i], num[r][j]);
        }
    }
    return 0;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> num[i][j];
        }
    }
    if (dfs(1)) {
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}
