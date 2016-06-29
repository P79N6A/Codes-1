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
const int MAXN = 3e3 + 111;

vector<int> G[MAXN];
ll ans = 0;
bool mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    while (m --) {
        scanf("%d%d", &u, &v);
        mp[u][v] = 1;
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                ll tol = 0;
                for (int k = 0; k < G[i].size(); ++k) {
                    int v = G[i][k];
                    if (mp[v][j]) ++tol;
                }
                ans += (tol - 1) * tol / 2;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
