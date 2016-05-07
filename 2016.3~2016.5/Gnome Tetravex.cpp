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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

struct Square {
    int u, r, d, l;
}sq[30];
int mp[10][10], sum[30];
int n, ed;

bool dfs(int p) {
    if (p == ed) {
        return 1;
    }

    int x = p / n, y = p % n;
    for (int i = 0; i < ed; ++i) {
        if (!sum[i]) continue;
        if (x > 0 && sq[mp[x - 1][y]].d != sq[i].u) continue;
        if (y > 0 && sq[mp[x][y - 1]].r != sq[i].l) continue;
        mp[x][y] = i;
        --sum[i];
        if (dfs(p + 1)) return 1;
        ++sum[i];
    }
    return 0;
}

int main()
{
    int kase = 0;
    while (~scanf("%d", &n) && n) {
        ed = n * n;
        for (int i = 0; i < ed; ++i) {
            sum[i] = 0;
            scanf("%d%d%d%d", &sq[i].u, &sq[i].r, &sq[i].d, &sq[i].l);
            bool flag = 1;
            for (int j = 0; j < i; ++j) {
                if (sq[i].u == sq[j].u && sq[i].r == sq[j].r
                    && sq[i].d == sq[j].d && sq[i].l == sq[j].l) {
                    ++sum[j];
                    flag = 0;
                    break;
                }
            }
            if (flag) sum[i] = 1;
        }

        if (kase) putchar('\n');
        if (dfs(0)) printf("Game %d: Possible\n", ++kase);
        else printf("Game %d: Impossible\n", ++kase);
    }
    return 0;
}
