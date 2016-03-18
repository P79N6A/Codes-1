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
const int MAXN = 1e6 + 111;

char orgc[5][5];
int mp[5][5], x[20], y[20], ansx[20], ansy[20], ans;

bool ok() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) if (mp[i][j] == 0)
            return 0;
    return 1;
}

void flip(int s) {
    int x = s / 4, y = s % 4;
    int g = 4;
    while (--g >= 0) {
        mp[g][y] = !mp[g][y];
        mp[x][g] = !mp[x][g];
    }
    mp[x][y] = !mp[x][y];
}

void dfs(int s, int cnt) {
    if (ok()) {
        if (ans > cnt) {
            ans = cnt;
            for (int i = 0; i < ans; ++i) {
                ansx[i] = x[i] + 1;
                ansy[i] = y[i] + 1;
            }
        }
    }

    if (s >= 16) return;

    dfs(s + 1, cnt);

    flip(s);
    x[cnt] = s / 4, y[cnt] = s % 4;
    dfs(s + 1, cnt + 1);

    flip(s); // »¹Ô­
}

int main()
{
    ans = INF;
    for (int i = 0; i < 4; ++i) scanf("%s", &orgc[i]);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            if (orgc[i][j] == '+') mp[i][j] = 0;
            else mp[i][j] = 1;
        }

    dfs(0, 0);

    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i)
        printf("%d %d\n", ansx[i], ansy[i]);
    return 0;
}
