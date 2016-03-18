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
const int MAXN = 1e3 + 111;

ll a, b, x;

int main()
{
    int n;
    scanf("%d", &n);
    a = b = 0;
    for (int i = 0; i < n; ++i) scanf("%I64d", &x), a |= x;
    for (int i = 0; i < n; ++i) scanf("%I64d", &x), b |= x;
    printf("%I64d\n", a + b);
    return 0;
}
