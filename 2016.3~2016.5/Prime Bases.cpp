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

int prime[50], cnt, sum[50];
int a[50];

void init() {
    cnt = 0;
    sum[0] = 1;
    prime[cnt++] = 1;
    for (int i = 2; i <= 30; ++i) {
        bool ok = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) prime[cnt++] = i;
    }
    --cnt;
    for (int i = 1; i < cnt; ++i) {
        sum[i] = sum[i - 1] * prime[i];
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
        cout << n << " =";
        for (int i = cnt - 1; i > 0; --i) {
            if (n / sum[i] == 0) {
                a[i] = 0;
                continue;
            }
            a[i] = n / sum[i];
            n -= a[i] * sum[i];
        }
        bool first = 0;
        if (n) cout << " 1", first = 1;
        for (int i = 1; i < cnt; ++i) {
            if (a[i]) {
                if (first) cout << " +";
                first = 1;
                cout << ' ' << a[i];
                for (int j = 1; j <= i; ++j) {
                    cout << '*' << prime[j];
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
