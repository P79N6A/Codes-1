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

const int MAXN = 1001;
const int MOD = 1e9 + 7;

int c[MAXN][MAXN];
int color[MAXN];

void init() {
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || i == j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main()
{
    init();
    int k;
    while (cin >> k) {
        ll sum = 0, ans = 1;
        for (int i = 0; i < k; ++i) cin >> color[i], sum += color[i];
        for (int i = k - 1; i > 0; --i) {
            --color[i];
            --sum;
            if (color[i] > 0) {
                ans = (ans * c[sum][color[i]]) % MOD;
                sum -= color[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
