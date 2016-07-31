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
const int MAXN = 111;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, x, y, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        int mx = 0, p = INF;
        memset(a, -1, sizeof a);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            a[x] = y;
        }
        int sum = 0;
        if (a[1] == -1) a[1] = 100;
        if (a[2] == -1) a[2] = a[1];
        a[n + 1] = 0;
        for (int i = 3; i <= n; ++i) {
            if (a[i] == -1) {
                for (int j = i + 1; j <= n + 1; ++j) {
                    if (a[j] != -1) {
                        a[i] = a[j];
                        break;
                    }
                }
            }
            sum += a[i];
        }
        int up = a[1] + a[2];
        sum += up;
        int gcd = __gcd(up, sum);
        printf("%d/%d\n", up / gcd, sum / gcd);
    }
    return 0;
}
