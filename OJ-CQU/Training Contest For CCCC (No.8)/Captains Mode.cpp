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

const int INF = 0x3f3f3f3f;
const int MAXN = 111;

int val[MAXN], n, m;
int dp[1 << 20][30];
bool vis[1 << 20][30];
string op[30];
int team[30];

bool cmp(int a, int b) {return a > b;}

int dfs(int s, int d) {
    if (vis[s][d]) return dp[s][d];
    vis[s][d] = 1;
    int &ret = dp[s][d];
    if (d == m) return 0;
    if (op[d] == "p") {
        for (int i = 0; i < m; ++i) {
            if ((s & (1 << i)) == 0) {
                ret = dfs(s | (1 << i), d + 1) + (team[d] ? -val[i] : val[i]);
                break;
            }
        }
    }
    else {
        ret = team[d] ? INF : -INF;
        for (int i = 0; i < m; ++i) {
            if ((s & (1 << i)) == 0) {
                if (team[d]) {
                    ret = min(ret, dfs(s | (1 << i), d + 1));
                }
                else ret = max(ret, dfs(s | (1 << i), d + 1));
            }
        }
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    sort(val, val + n, cmp);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> op[i] >> team[i];
        --team[i];
    }
    cout << dfs(0, 0) << '\n';
    return 0;
}
