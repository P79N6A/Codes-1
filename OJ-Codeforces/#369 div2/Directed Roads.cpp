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
const int MAXN = 2e5 + 111;
const int MOD = 1e9 + 7;

vector<int> G[MAXN];
ll dp[MAXN], ans, cnt;
int scc[MAXN], dfn[MAXN], low[MAXN], indx, id, sta[MAXN], top;
bool in[MAXN];

void tarjan(int u, int f) {
	dfn[u] = low[u] = ++indx;
	sta[top++] = u;
	in[u] = 1;
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if (in[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int v, sum = 0;
		do {
			v = sta[--top];
			in[v] = 0;
			++sum;
		} while (u != v);
		if (sum == 1) ans = ans * 2 % MOD;
		else ans = ans * (dp[sum] - 2) % MOD;
	}
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, x; scanf("%d", &n);
    dp[0] = 1;
    indx = id = 0;
    for (int i = 1; i <= n; ++i) {
    	dp[i] = dp[i - 1] * 2 % MOD;
    	dfn[i] = 0;
    	scanf("%d", &x);
    	G[i].push_back(x);
    }
    ans = 1;
    for (int i = 1; i <= n; ++i) {
    	if (!dfn[i]) tarjan(i, i);
    }
    printf("%lld\n", (ans + MOD) % MOD);
    return 0;
}