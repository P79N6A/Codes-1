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
const int MAXN = 511;

bool vis[MAXN][MAXN];

int main()
{
    int x, y, x0, y0;
    string s;
    cin >> x >> y >> x0 >> y0 >> s;

    int total = x * y;
    int cnt = 1;
    vis[x0][y0] = 1;
    cout << 1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (i == s.length() - 1)
        {
            cout << ' ' << total - cnt;
            continue;
        }
        if (s[i] == 'U' && x0 - 1 >= 1) x0 -= 1;
        else if (s[i] == 'D' && x0 + 1 <= x) x0 += 1;
        else if (s[i] == 'L' && y0 - 1 >= 1) y0 -= 1;
        else if (s[i] == 'R' && y0 + 1 <= y) y0 += 1;
        if (vis[x0][y0]) cout << ' ' << 0;
        else vis[x0][y0] = 1, cout << ' ' << 1, ++cnt;
    }
    cout << '\n';
    return 0;
}
