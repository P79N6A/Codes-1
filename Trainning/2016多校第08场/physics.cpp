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
const int MAXN = 1e5 + 111;

double x, v[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, q, k; scanf("%d", &t);
    double c, time;
    while (t --) {
        scanf("%d%lf", &n, &c);
        for (int i = 0; i < n; ++i) scanf("%lf%lf%d", &v[i], &x, &q);
        sort(v, v + n);
        scanf("%d", &q);
        while (q --) {
            scanf("%lf%d", &time, &k);
            printf("%.3f\n", sqrt(v[k - 1] * v[k - 1] + 2 * c * time));
        }
    }
    return 0;
}
