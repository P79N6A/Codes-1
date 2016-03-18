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
const int MAXN = 1e3 + 111;

struct Cake {
    int a, b, id;
    bool operator < (const Cake &t)const {
        return a < t.a;
    }
}cake[MAXN], cakeb[MAXN], cakeo[MAXN];

bool take[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &cake[i].a, &cake[i].b);
            cake[i].id = i;
            cakeo[i].a = cake[i].a, cakeo[i].b = cake[i].b;
        }
        sort(cake, cake + n);
        memset(take, 0, sizeof take);

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cur = cake[i].id;
            if (!take[cur]) {
                take[cur] = 1;
                int curb = cakeo[cur].b;
                int mx = 0, mxid = -1;
                int mi = INF, miid = -1;
                for (int j = 0; j < n; ++j) {
                    if (!take[j]) {
                        if (curb > cakeo[j].b) {
                            if (cakeo[j].a > mx) {
                                mx = cakeo[j].a;
                                mxid = j;
                            }
                        }
                        else {
                            if (cakeo[j].a < mi) {
                                mi = cakeo[j].a;
                                miid = j;
                            }
                        }
                    }
                }
                if (miid != -1) {
                    take[miid] = 1;
                    ans += cakeo[cur].a;
                }
                else {
                    take[mxid] = 1;
                    ans += cakeo[mxid].a;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
