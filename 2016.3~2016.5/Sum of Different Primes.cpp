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
const int MAXN = 1121;

bool vis[MAXN];
vector<int> prime;
int dp[20][MAXN];

void init() {
    prime.push_back(0);
    for (int i = 2; i < MAXN; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
            for (int j = i; j < MAXN; j += i)
                vis[j] = 1;
        }
    }

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i < prime.size(); ++i) {
        for (int j = MAXN - 1; j >= prime[i]; --j) {
            for (int k = 14; k >= 1; --k) {
                dp[k][j] += dp[k - 1][j - prime[i]];
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int n, k, num = prime.size();
    while (~scanf("%d%d", &n, &k) && (n | k)) {
        printf("%d\n", dp[k][n]);
    }
    return 0;
}
