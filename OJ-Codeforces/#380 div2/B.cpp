#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

bool has[MAXN][MAXN][4];
int mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		scanf("%d", &mp[i][j]);
    		has[i][j][0] = has[i - 1][j][0] | mp[i][j];
    		has[i][j][2] = has[i][j - 1][2] | mp[i][j];
    	}
    }
    for (int i = n; i >= 1; --i) {
    	for (int j = m; j >= 1; --j) {
    		has[i][j][1] = has[i + 1][j][1] | mp[i][j];
    		has[i][j][3] = has[i][j + 1][3] | mp[i][j];
    	}
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		if (mp[i][j]) continue;
    		for (int k = 0; k < 4; ++k) if (has[i][j][k]) ++ans;
    	}
    }
    printf("%d\n", ans);
    return 0;
}