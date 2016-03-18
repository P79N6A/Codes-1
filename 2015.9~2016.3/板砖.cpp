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

void dfs(int n, int &ans)
{
    if (n == 1 || n == 0) return;
    if (n % 2)
    {
        ans += 1;
        dfs(n / 2 + 1, ans);
        dfs(n / 2, ans);
    }
    else dfs(n / 2, ans), dfs(n / 2, ans);
}

int main()
{
    int t, n;
    cin >> t;
    while (t --)
    {
        int ans = 0;
        cin >> n;
        dfs(n, ans);
        cout << ans << '\n';
    }
    return 0;
}
