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

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        n *= 2;
        n += 1;
        int base = 1;
        int len = 0;
        while (base <= n) {
            ++len;
            base *= 3;
        }
        if (base == n * 3) --len;
        printf("%d\n", len);
    }
    return 0;
}
