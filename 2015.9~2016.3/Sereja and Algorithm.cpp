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
const int MAXN = 1e5 + 111;

int x[MAXN], y[MAXN], z[MAXN], m;
string s;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> s >> m;
    int l, r;
    for (int i = 0; i < s.length(); ++i)
    {
        x[i + 1] += x[i];
        y[i + 1] += y[i];
        z[i + 1] += z[i];
        if (s[i] == 'x') ++x[i + 1];
        if (s[i] == 'y') ++y[i + 1];
        if (s[i] == 'z') ++z[i + 1];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        --l;
        int xx = x[r] - x[l];
        int yy = y[r] - y[l];
        int zz = z[r] - z[l];
        if (r - l < 3 || abs(xx - yy) < 2 && abs(xx - zz) < 2 && abs(yy - zz) < 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
