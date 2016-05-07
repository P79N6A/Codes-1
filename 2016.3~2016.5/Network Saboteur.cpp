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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 51;

int mp[MAXN][MAXN], ans = 0, n;
bool in[MAXN];

void dfs(int x, int sum) {
    if (x == n) {
        ans = max(ans, sum);
        return;
    }
    in[x] = 1;
    int add = 0;
    for (int i = 0; i < x; ++i) {
        if (in[i] != in[x])
            add += mp[i][x];
    }
    dfs(x + 1, sum + add);

    in[x] = 0;
    add = 0;
    for (int i = 0; i < x; ++i) {
        if (in[i] != in[x])
            add += mp[i][x];
    }
    dfs(x + 1, sum + add);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &mp[i][j]);
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}
