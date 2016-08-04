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

ll a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        for (int i = n - 2; i >= 0; --i) if (a[i + 1] < 0) a[i] += a[i + 1];
        int ans = 0;
        for (int i = 0; i < n; ++i) if (a[i] >= 0) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
