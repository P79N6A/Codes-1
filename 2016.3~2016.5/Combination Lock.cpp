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
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, t1, t2, t3;
    while (~scanf("%d%d%d%d", &n, &t1, &t2, &t3) && (n|t1|t2|t3)) {
        double sum = 0;
        sum += 3 * n + (n - 1) / 2.0;
        if (t1 <= t2) sum += t2 - t1;
        else sum += n - (t1 - t2);
        if (t2 >= t3) sum += t2 - t3;
        else sum += n - (t3 - t2);
        sum = round(sum * 1000) / 1000;
        printf("%.3f\n", sum);
    }
    return 0;
}
