/*
  画图，找规律，发现答案都在那个闭合区域内。
  所以我们只用找到上凸点和下凸点，就能将整个
  图形的轮廓概括下来。
  然后根据轮廓，下凸点中查找a，确定b的下界，
  上凸点中查找a，确定b的上界，就可以了。
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
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

int x[MAXN];
pii low[MAXN * MAXN], up[MAXN * MAXN];
int lnt, unt;

inline void preWork(int n) {
    lnt = 0, unt = 0;
    for (int i = 0; i < n; ++i) {
        int zero = 0, one = 0;
        for (int j = i; j < n; ++j) {
            if (j % 2) one += x[j];
            else zero += x[j];
            if (i % 2 && j % 2) up[unt++] = make_pair(zero, one);
            if (i % 2 == 0 && j % 2 == 0) low[lnt++] = make_pair(zero, one);
        }
    }
    sort(up, up + unt);
    int len = 0, j;
    /* 查找上凸点：
             .              .
        .  . .    -->  .
      . .    .        .
      . .
     */
    for (int i = 0; i < unt; i = j) {
        for (j = i; j < unt && up[i].first == up[j].first; ++j);
        if (!len || up[len - 1].second < up[j - 1].second )
            up[len++] = up[j - 1];
    }
    unt = len;
    sort(low, low + lnt);
    len = 0;
    for (int i = 0; i < lnt; i = j) {
        for (j = i; j < lnt && low[i].first == low[j].first; ++j);
        while (len && low[len - 1].second >= low[i].second) --len;
        low[len++] = low[i];
    }
    lnt = len;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
        preWork(n);
        int a, b;
        while (m --) {
            scanf("%d%d", &a, &b);
            pii t = make_pair(a, -INF);
            int pos = lower_bound(low, low + lnt, t) - low;
            if (pos == lnt) {
                putchar('0');
                continue;
            }
            int x1 = low[pos].first, y1 = low[pos].second;
            t.second = INF;
            pos = lower_bound(up, up + unt, t) - up;
            if (pos == unt) --pos;
            if (up[pos].first > a) --pos;
            int x2 = up[pos].first, y2 = up[pos].second;
            if (y1 <= b && b <= y2) putchar('1');
            else putchar('0');
        }
        putchar('\n');
    }
    return 0;
}
