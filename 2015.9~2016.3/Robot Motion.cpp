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

char mp[MAXN][MAXN];
int num[MAXN][MAXN];
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};
map<char, int> id;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m, n, w;
    id['N'] = 0, id['E'] = 1, id['S'] = 2, id['W'] = 3;
    while (~scanf("%d%d%d", &n, &m, &w) && (m | n | w)) {
        for (int i = 0; i < n; ++i) scanf("%s", &mp[i]);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) num[i][j] = 0;

        int cnt = 0, lop = 0;
        int nx = 0, ny = w - 1;
        bool flag = 1;
        while (1) {
            if (num[nx][ny]) {
                lop = cnt - num[nx][ny] + 1;
                break;
            }
            ++cnt;
            num[nx][ny] = cnt;
            int op = id[mp[nx][ny]];
            nx += dirx[op], ny += diry[op];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        }

        if (lop) printf("%d step(s) before a loop of %d step(s)\n", cnt - lop, lop);
        else printf("%d step(s) to exit\n", cnt);
    }
    return 0;
}
