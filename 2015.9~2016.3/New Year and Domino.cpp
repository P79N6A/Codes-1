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

char mp[MAXN][MAXN];
int row[MAXN][MAXN], col[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(0);
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int h, w, q; cin >> h >> w;
    for (int i = 1; i <= h; ++i) cin >> (mp[i] + 1);

    for (int i = 1; i <= h; ++i)
        for (int j = 2; j <= w; ++j){
            row[i][j] = row[i][j - 1];
            if (mp[i][j] == '.' && mp[i][j - 1] == '.') ++row[i][j];
        }
    for (int i = 1; i <= w; ++i)
        for (int j = 2; j <= h; ++j){
            col[j][i] = col[j - 1][i];
            if (mp[j][i] == '.' && mp[j - 1][i] == '.') ++col[j][i];
    }

    //for (int i = 1; i <= h; ++i, cout << '\n') for (int j = 1; j <= w; ++j) cout << col[i][j] << ' ';

    cin >> q;
    int a, b, c, d;
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b >> c >> d;
        int ans = 0;
        for (int j = a; j <= c; ++j) ans += row[j][d] - row[j][b];
        for (int j = b; j <= d; ++j) ans += col[c][j] - col[a][j];
        cout << ans << '\n';
    }
    return 0;
}
