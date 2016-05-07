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
const int MAXN = 2e6 + 111;
vector<int> prime;

bool vis[MAXN];

void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
            for (int j = i; j < MAXN; j += i) {
                vis[j] = 1;
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
    int n;
    while (cin >> n && n) {
        int p = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
        int ans = 0;
        if (p != 0 && prime[p - 1] <= n && prime[p] != n) ans = prime[p] - prime[p - 1];
        cout << ans << '\n';
    }
    return 0;
}
