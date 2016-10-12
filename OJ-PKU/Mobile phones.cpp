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
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

int n = 1024;
int bit[MAXN][MAXN];

inline void update(int x, int y, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j))
            bit[i][j] += val;
    }
}

int query(int x, int y) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j))
            ret += bit[i][j];
    }
    return ret;
}

int main()
{
    int op, x, y, val, x1, y1, x2, y2;
    while (~scanf("%d", &op) && op != 3) {
        if (op == 0) {
            scanf("%d", &op);
            memset(bit, 0, sizeof bit);
        }
        else if (op == 1) {
            scanf("%d%d%d", &x, &y, &val);
            ++x, ++y;
            update(x, y, val);
        }
        else {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            ++x1, ++y1, ++x2, ++y2;
            printf("%d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
        }
    }
    return 0;
}
