/*
 10010010，先统计比10000000小的数量，然后以1000000为
 基地，碰到1就化1为0，然后统计后方的可行数量。
*/
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
int sum[40], bit[40];

void init() {
    for (int i = 0; i <= 34; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j || j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= 33; ++i) {
        for (int j = (i + 1) / 2; j < i; ++j) {
            sum[i] += c[i - 1][j];
        }
        sum[i] += sum[i - 1];
    }
}

int cal(int x) {
    if (x <= 1) return 0;
    int indx = 0;
    int temp = x;
    while (x) {
        bit[indx++] = x & 1;
        x >>= 1;
    }
    int ret = sum[indx - 1] + (__builtin_popcount(temp) <= (indx + 1) / 2);
//    pr(ret)
    int one = 1, zero = 0;
    for (int i = indx - 2; i >= 0; --i) {
        if (bit[i]) {
            ++zero;
            for (int j = i; j >= 0 && zero + j >= one + i - j; --j) {
                ret += c[i][j];
            }
            //pr(ret)
            ++one;
            --zero;
        }
        else ++zero;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    init();
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("%d\n", cal(b) - cal(a - 1));
    }
    return 0;
}
