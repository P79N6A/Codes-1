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

bool va[MAXN];
bool vb[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n, d, r;
    cin >> t;
    while (t --) {
        cin >> n >> d >> r;
        int ans = 1;
        memset(va, 0, sizeof va);
        memset(vb, 0, sizeof vb);
        int tempa = d;
        int tempb = r;
        while (1) {
            if (vb[tempa]) break;
            if (va[tempb]) break;
            vb[tempb] = 1;
            va[tempa] = 1;
            if (tempa == tempb) break;
            tempb = (tempb + r) % n;
            tempa = (tempa + d) % n;
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
