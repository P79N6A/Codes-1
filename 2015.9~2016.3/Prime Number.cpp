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
const int MAXN = 1e6 + 111;

bool is[MAXN];
vector<int> prime;

int main()
{
    for (ll i = 2; i < MAXN; ++i) {
        if (!is[i]) {
            prime.push_back(i);
            for (ll j = i * i; j < MAXN; j += i) {
                is[j] = 1;
            }
        }
    }

    int n;
    while (cin >> n) {
        int ans = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
        cout << ans << '\n';
    }
    return 0;
}
