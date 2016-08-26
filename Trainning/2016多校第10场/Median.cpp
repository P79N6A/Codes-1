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
const int MAXN = 1e5 + 111;

double a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m, x1, y1, x2, y2; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", &a[i]);
        }
        while (m --) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }

        }
    }
    return 0;
}
