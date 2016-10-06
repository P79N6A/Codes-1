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
const int MAXN = 1e6 + 111;

bool visr[MAXN], visc[MAXN];
ll c, r, ccnt, rcnt;
char op[2];

int main()
{
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    ll n, q; scanf("%I64d%I64d", &n, &q);
    ll x;
    ll sum = (1 + n) * n / 2, ans;
    while (q --) {
        scanf("%s%I64d", op, &x);
        if (op[0] == 'R') {
            if (visr[x]) ans = 0;
            else {
                ans = sum + n * x;
                ans -= ccnt * x + c;
                ++rcnt;
                r += x;
                visr[x] = 1;
            }
        }
        else {
            if (visc[x]) ans = 0;
            else {
                ans = sum + n * x;
                ans -= rcnt * x + r;
                ++ccnt;
                c += x;
                visc[x] = 1;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
