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

int c[40][40];

void init() {
    for (int i = 0; i <= 32; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j || j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int getlen(int x) {
    int ret = 0;
    while (x) {
        ++ret;
        x /= 2;
    }
    return ret;
}

int getsum(int x) {
    int len = getlen(x);
    int one = 0;
    int ret = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (x & (1 << i)) {
            ++one;
            int lef = min(len / 2 - one, i);
            if (lef < 0) continue;
            else if (lef == 0 && i) ++ret;
            else if (i){
                for (int j = 0; j <= lef; ++j) {
                    ret += c[i][j];
                }
                if (i) {
                    for (int j = 0; j < lef; ++j) ret -= c[i - 1][j];
                }
            }
        }
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int l, r;
    int cnt = 0;
    for (int i= 1; i <= 40; ++i) {
        int x = i, len = 0;
        while (x) {
            ++len; x/= 2;
        }
        if (__builtin_popcount(i) <= len / 2) ++cnt;
        cout << i << ":" << cnt << endl;
    }
    while (~scanf("%d%d", &l, &r)) {
        //printf("%d\n", getsum(r) - getsum(l - 1));
        for (int i = 1; i <= 40; ++i) cout << i << ": " << getsum(i) << endl;
    }
    return 0;
}
