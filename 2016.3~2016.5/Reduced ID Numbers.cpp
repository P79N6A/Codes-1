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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

bool vis[MAXN], ff[MAXN];
int a[400];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j)
                vis[abs(a[i] - a[j])] = 1;
        }

        for (int i = n; ; ++i) {
            bool flag = 1;
            if (!vis[i]) {
                memset(ff, 0, (i + 1) * sizeof(bool));
                for (int j = 0; j < n; ++j) {
                    if (ff[a[j] % i]) {
                        flag = 0;
                        break;
                    }
                    ff[a[j] % i] = 1;
                }
                if (flag) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
