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

const int INF = 0x7f7f7f7f;
const int MAXN = 131;

int p[MAXN], w[MAXN];
bool vis[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        memset(vis, 0, sizeof vis);
        vector<int> org;
        scanf("%d", &n);
        p[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", p + i);
        }
        for (int i = 1; i <= n; ++i) {
            int cnt = p[i] - p[i - 1];
            for (int j = 0; j < cnt; ++j) {
                org.push_back(0);
            }
            org.push_back(1);
        }

        int cnt = 0;
        for (int i = 0; i < org.size(); ++i) {
            if (org[i] == 1) {
                vis[i] = 1;
                int num = 1;
                for (int j = i - 1; j >= 0; --j) {
                    if (org[j] == 1) ++num;
                    else if (vis[j] == 0) {
                        vis[j] = 1;
                        w[cnt++] = num;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            printf("%d", w[i]);
            if (i == n - 1) puts("");
            else putchar(' ');
        }
    }
    return 0;
}
