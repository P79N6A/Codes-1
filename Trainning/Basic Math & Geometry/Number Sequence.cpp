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
const int MAXN = 41111;

ll sz[MAXN], sum[MAXN];

inline void init() {
    for (int i = 1; i < MAXN; ++i) {
        sz[i] = sz[i - 1] + (int)log10(i) + 1;
        sum[i] = sum[i - 1] + sz[i];
    }
//    pr(sum[MAXN - 1])
}

inline int getAns(int n) {
    int in = lower_bound(sum + 1, sum + MAXN, n) - sum; // 在第几个sum中
    int pos = n - sum[in - 1]; // 在sz的什么位置
    int i = 1, len = 0;
    // 在sz数组中的第几个数中
    while ((len = len + (int)log10(i) + 1) < pos) {
        ++i;
    }
    int lef = len - pos;
    return i / (int)pow(10, lef) % 10;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        printf("%d\n", getAns(n));
    }
    return 0;
}
