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

int mp[11][11];
struct P {
    int id, deg;
    bool operator < (const P&t)const{
        return deg > t.deg;
    }
}frog[11];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        memset(mp, 0, sizeof mp);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &frog[i].deg), frog[i].id = i;

        bool flag = 1;
        for (int i = n; i > 0; --i) {
            sort(frog, frog + n);
            for (int j = 0; j < frog[0].deg; ++j) {
                --frog[j + 1].deg;
                mp[frog[0].id][frog[j + 1].id] = 1;
                mp[frog[j + 1].id][frog[0].id] = 1;
                if (frog[j + 1].deg < 0) {
                    flag = 0;
                    break;
                }
            }
            frog[0].deg = 0;
        }

        if (flag) {
            printf("YES\n");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j > 0) putchar(' ');
                    printf("%d", mp[i][j]);
                }
                putchar('\n');
            }
        }
        else printf("NO\n");

        if (t) putchar('\n');
    }
    return 0;
}
