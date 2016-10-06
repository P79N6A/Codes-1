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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

char name[MAXN][300];
struct P {
    int id, val;
    bool operator < (const P& t)const {
        if (val == t.val) return id > t.id;
        return val < t.val;
    }
}p[MAXN];
int let[MAXN];
int ans[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    scanf("%d", &t);
    int k, m, q;
    while (t --) {
        scanf("%d%d%d", &k, &m, &q);
        for (int i = 1; i <= k; ++i) {
            scanf("%s%d", name[i], &p[i].val);
            p[i].id = i;
        }
        memset(let, 0, sizeof let);
        int tt, nn;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &tt, &nn);
            let[tt] = nn;
        }

        int top = 0;
        int cnt = 0;
        priority_queue<P> que;
        for (int i = 1; i <= k; ++i) {
            que.push(p[i]);
            while (let[i] -- && que.size()) {
                int x = que.top().id; que.pop();
                ans[++cnt] = x;
            }
        }
        while (que.size()) {
            int x = que.top().id; que.pop();
            ans[++cnt] = x;
        }
        int x;
        for (int i = 0; i < q; ++i) {
            scanf("%d", &x);
            printf("%s", name[ans[x]]);
            if (i != q - 1) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}
