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
const int MAXN = 1e5 + 111;

int div1[MAXN], div2[MAXN];
bool vis[MAXN];
int cnt1 = 0, cnt2 = 0;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, u, v;
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        div2[cnt2++] = u;
        div1[cnt1++] = v;
    }
    if (m == 0) {
        printf("%d\n", n - 1);
        return 0;
    }
    sort(div1, div1 + cnt1);
    sort(div2, div2 + cnt2);
    cnt1 = unique(div1, div1 + cnt1) - div1;
    cnt2 = unique(div2, div2 + cnt2) - div2;
    int mx = div2[cnt2 - 1];
    int mi = div1[0];
    bool flag = 0;
    for (int i = 0; i < cnt2; ++i) vis[div2[i]] = 1;
    for (int i = 0; i < cnt1; ++i) {
        if (vis[div1[i]]) {
            flag = 1;
            break;
        }
        vis[div1[i]] = 1;
    }
    if (flag || mx >= mi) {
        printf("0\n");
    }
    else {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (i <= mx) vis[i] = 1;
            else if (!vis[i] && i < mi) ++cnt;
        }
        printf("%d\n", cnt + 1);
    }
    return 0;
}
