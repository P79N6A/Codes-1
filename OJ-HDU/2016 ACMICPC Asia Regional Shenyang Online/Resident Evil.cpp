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
#define lowbit(x) x & (-x)
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 3e3 + 2;

int n;
bool c[50][MAXN][MAXN];

inline void modify(int o, int x1, int y1, int x2, int y2, bool val) {
    for (int i = x1; i <= x2; i += lowbit(i)) {
        for (int j = y1; j <= y2; j += lowbit(j))
            c[o][i][j] ^= val;
    }
}

bool sum(int o, int x1, int y1, int x2, int y2) {
    bool ret = 0;
    for (int i = x2; i >= x1; i -= lowbit(i)) {
        for (int j = y2; j >= y1; j -= lowbit(j))
            ret ^= c[o][i][j];
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, x1, y1, x2, y2, k, a, b;
    char op[2];
    while (~scanf("%d%d", &n, &m)) {
        memset(c, 0, sizeof c);
        while (m --) {
            scanf("%s%d%d%d%d", op, &x1, &y1, &x2, &y2);
            if (op[0] == 'P') {
                scanf("%d", &k);
                while (k --) {
                    scanf("%d%d", &a, &b);
                    modify(a - 1, x1, y1, x2, y2, b % 2);
                }
            }
            else {
                for (int i = 0; i < 50; ++i) {
                    printf("%d ", sum(i, x1, y1, x2, y2) + 1);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}
