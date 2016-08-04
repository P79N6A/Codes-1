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
const int MAXN = 1111;

double dp[MAXN][MAXN][2];

double dfs(int w, int b, int who) {
    if (w < 0 || b < 0) return 0;
    double &ret = dp[w][b][who];
    if (ret != -1) return ret;
    if (!b && w && !who) return ret = 1;
    if (b && !w && !who) return ret = 0;
    if (who && (!w || !b)) return ret = 0;
    if (!w && !b) return ret = 0;
    ret = 0;
    double sum = w + b;
    if (!who) {
        ret += w / sum + dfs(w, b - 1, 1) * b / sum;
    }
    else {
        if (w && b) {
            ret += dfs(w - 1, b - 1, 0) * (b * w / (sum * (sum - 1)));
            if (b >= 2) {
                ret += dfs(w, b - 2, 0) * (b * (b - 1)) / (sum * (sum - 1));
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
    int w, b;
    while (cin >> w >> b) {
        for (int i = 0; i <= w; ++i) {
            for (int j = 0; j <= b; ++j) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        printf("%.10f\n", dfs(w, b, 0));
    }
    return 0;
}
