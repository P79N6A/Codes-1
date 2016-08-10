/*
  边随意建，并不要求最少。所以从点数小的开始贪心，前面可行点
  都可拿来使用。
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
const int MAXN = 1111;

struct P {
    int lk, id;
    bool operator < (const P&t)const {
        return lk < t.lk;
    }
}a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    for (int t, kase = scanf("%d", &t); kase <= t; ++kase) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].lk);
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        bool flag = 1;
        vector<pii> ans;
        for (int i = 1; i <= n; ++i) {
            int need = a[i].lk;
            if (need == 0) continue;
            for (int j = 1; j < i; ++j) {
                ans.push_back(make_pair(a[i].id, a[j].id));
                if (--need == 0) break;
            }
            if (need) {
                flag = 0;
                break;
            }
        }
        printf("Case #%d: ", kase);
        if (flag) {
            puts("Yes");
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); ++i) {
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }
        else puts("No");
    }
    return 0;
}
