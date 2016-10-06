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
const int MAXN = 1e6 + 111;

ll c[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k; scanf("%d%d", &n, &k);
    ll flag = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &c[i]);
        flag = flag * c[i] / __gcd(flag, c[i]) % k;
    }
    if (!flag) puts("Yes");
    else puts("No");
    return 0;
}
