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

int h[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    for (int i = 5; i < MAXN; i += 4) {
        for (int j = 5; j < MAXN; j += 4) {
            int x = i * j;
            if (x >= MAXN) break;
            if (!h[i] && !h[j]) {
                h[x] = 1;
            }
            else h[x] = -1;
        }
    }

    int cnt = 0;
    for (int i = 1; i < MAXN; ++i) {
        if (h[i] == 1) ++cnt;
        h[i] = cnt;
    }

    int n;
    while (cin >> n && n) {
        cout << n << ' ' << h[n] << '\n';
    }
    return 0;
}
