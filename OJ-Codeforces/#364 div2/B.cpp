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
const int MAXN = 1e5 + 111;

bool row[MAXN], col[MAXN];
ll r = 0, c = 0;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    ll ans = n * n;
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        if (!row[x]) {
            ans -= (n - c);
            ++r;
        }
        if (!col[y]) {
            ans -= (n - r);
            ++c;
        }
        row[x] = col[y] = 1;
        cout << ans << ' ';
    }
    return 0;
}
