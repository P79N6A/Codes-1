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

int n, k, ans;
char mp[10][10];
bool col[10];

void dfs(int x, int y, int dep) {
    //cout << '(' << x << ',' << y << ')' << '\n';
    //pr(dep);
    if (dep == k) {
        ++ans; return;
    }
    for (int i = x + 1; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            //cout << i << ',' << j << endl;
            //cout << mp[i][j] << endl;
            if (!col[j] && mp[i][j] == '#') {
                col[j] = 1;
                dfs(i, j, dep + 1);
                col[j] = 0;
            }
        }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &k) && n != -1 && k != -1) {
        gets(mp[0]);
        ans = 0;
        for (int i = 0; i < n; ++i) gets(mp[i]), col[i] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (mp[i][j] == '#') {
                    col[j] = 1;
                    dfs(i, j, 1);
                    col[j] = 0;
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
