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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;
const int mod = 9973;

char s[MAXN];
int sum[MAXN];

int quick_pow(int x, int p) {
    int ret = 1;
    while (p) {
        if (p & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        scanf("%s", s);
        int len = strlen(s);
        sum[0] = 1;
        for (int i = 0; i < len; ++i) {
            sum[i + 1] = (sum[i] * (s[i] - 28)) % mod;
        }
        int l, r;
        while (n --) {
            scanf("%d%d", &l, &r);
            int x = quick_pow(sum[l - 1], mod - 2);
            printf("%d\n", (sum[r] * x) % mod);
        }
    }
    return 0;
}
