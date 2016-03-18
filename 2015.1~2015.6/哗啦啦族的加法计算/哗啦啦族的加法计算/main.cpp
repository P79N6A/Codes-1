#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define BUG puts("I am bug")
#define XY(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int alp[27], num[27], n, ans, cnt;
string formu[11];
ll number[11];
bool vis[10];

bool judge()
{
    memset(number, 0, sizeof number);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < formu[i].size(); ++j)
        {
            if (j == 0 && num[formu[i][j] - 'A'] == 0)
                return false;
            number[i] += (ll)num[formu[i][j] - 'A'] * pow(10, formu[i].size() - j - 1);
        }
    }
    ll sum = 0;
    for (int i = 1; i < n; ++i)
        sum += number[i];
    //cout << sum << ' ' << number[n] << endl;
    if (sum == number[n])
        return true;
    else return false;
}

void dfs(int value, int node, int dep)
{
    num[node] = value;
    if (dep == cnt)
    {
        if (judge())
            ++ans;
        return;
    }
    for (int i = node + 1; i < 26; ++i)
    {
        if (alp[i] > 0)
        {
            for (int j = 0; j <= 9; ++j)
            {
                if (!vis[j])
                {
                    vis[j] = 1;
                    dfs(j, i, dep + 1);
                    vis[j] = 0;
                }
            }
            return;
        }
    }
}

int main() {
    while (cin >> n)
    {
        memset(alp, 0, sizeof alp);
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i)
        {
            cin >> formu[i];
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < formu[i].size(); ++j)
                ++alp[formu[i][j] - 'A'];
        cnt = 0;
        for (int i = 0; i < 26; ++i)
            if (alp[i] > 0)
                ++cnt;
        if (cnt > 10)
        {
            cout << 0 << '\n';
            continue;
        }
        ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (alp[i] > 0)
            {
                for (int j = 0; j <= 9; ++j)
                {
                    if (!vis[j])
                    {
                        vis[j] = 1;
                        dfs(j, i, 1);
                        vis[j] = 0;
                    }
                }
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
