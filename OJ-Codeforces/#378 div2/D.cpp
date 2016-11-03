#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

struct P {
    int a[3], id;
    void read(int ID) {
        id = ID;
        for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
        sort(a, a + 3);
    }
    bool operator < (const P &t) const {
        if (a[1] == t.a[1]) {
            if (a[2] == t.a[2]) return a[0] > t.a[0];
            return a[2] < t.a[2];
        }
        return a[1] < t.a[1];
    }
}p[MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        p[i].read(i);
    }
    sort(p + 1, p + 1 + n);
    int ans1 = 0, ans2 = 0;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i].a[0] > mx) {
            mx = p[i].a[0];
            ans1 = p[i].id;
            ans2 = 0;
        }
        int pos = i - 1;
        if (pos == 0) continue;
        if (p[i].a[1] != p[pos].a[1] || p[i].a[2] != p[pos].a[2]) continue;
        int nx = min(min(p[i].a[1], p[i].a[2]), p[i].a[0] + p[pos].a[0]);
        if (nx > mx) {
            mx = nx;
            ans1 = p[i].id;
            ans2 = p[pos].id;
        }
    }
    vector<int> ans;
    if (ans1) ans.push_back(ans1);
    if (ans2) ans.push_back(ans2);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}