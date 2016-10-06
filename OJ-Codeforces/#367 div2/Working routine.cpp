/*
  -----
  |   |  只改变周围一圈的指针变化，指针指向下方和右方两个方向
  -----
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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;

struct P {
    int val;
    int dir[2]; // 0: right; 1: down
}p[MAXN * MAXN];
int m;

int xy(int i, int j) {
    return i * (m + 1) + j;
}

inline void goTo(int &pos, int x, int y) {
    for (int i = 1; i < x; ++i) pos = p[pos].dir[1];
    for (int i = 1; i < y; ++i) pos = p[pos].dir[0];
}

inline void shift(int p1, int p2, int h, int w, int s) {
    for (int i = 0; i < h; ++i) {
        p1 = p[p1].dir[s];
        p2 = p[p2].dir[s];
        swap(p[p1].dir[1 - s], p[p2].dir[1 - s]);
    }
    s = 1 - s;
    for (int i = 0; i < w; ++i) {
        p1 = p[p1].dir[s];
        p2 = p[p2].dir[s];
        swap(p[p1].dir[1 - s], p[p2].dir[1 - s]);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q; scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &p[xy(i, j)].val);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            p[xy(i, j)].dir[0] = xy(i, j + 1);
            p[xy(i, j)].dir[1] = xy(i + 1, j);
        }
    }
    int x1, y1, x2, y2, h, w;
    while (q --) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
        int p1 = 0, p2 = 0;
        goTo(p1, x1, y1);
        goTo(p2, x2, y2);
        shift(p1, p2, h, w, 1);
        shift(p1, p2, w, h, 0);
    }
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        pos = p[pos].dir[1];
        int temp = pos;
        for (int j = 1; j <= m; ++j) {
            temp = p[temp].dir[0];
            printf("%d ", p[temp].val);
        }
        puts("");
    }
    return 0;
}
