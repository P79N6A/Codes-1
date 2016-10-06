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

int num[MAXN];
int range[MAXN];

int main()
{
     #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for (ll i = 1; i <= n; ++i) {
        scanf("%d", &num[i]);
        if ((i + 1) * i / 2 <= k)
            range[++cnt] = (i + 1) * i / 2;
    }
    int x = upper_bound(range + 1, range + 1 + cnt, k) - range - 1;
    int lef = k - range[x];
    if (lef == 0) lef = x;
    printf("%d\n", num[lef]);
    return 0;
}
