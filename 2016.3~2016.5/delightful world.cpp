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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 51;

char s[20][MAXN];
int num[20][MAXN];
int r[20], n, m, ans;
int temp[MAXN];
int p, mi;

void dfs(int pos, int lef) {
    if (lef == 0) {
        for (int i = pos; i < n; ++i) temp[i] = 1 - num[p][i];
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (temp[j] == num[i][j]) ++cnt;
            }
            if (cnt != r[i]) {
                return;
            }
        }
        ++ans;
        return;
    }
    if (pos >= n) return;

    temp[pos] = num[p][pos];
    dfs(pos + 1, lef - 1);
    temp[pos] = 1 - temp[pos];
    dfs(pos + 1, lef);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &m)) {
        p = 0, mi = 1000;
        for (int i = 0; i < m; ++i) {
            scanf("%s%d", s[i], &r[i]);
            for (int j = 0; j < n; ++j) num[i][j] = s[i][j] - '0';
            if (r[i] < mi) {
                mi = r[i];
                p = i;
            }
        }
        ans = 0;
        dfs(0, mi);
        printf("%d\n", ans);
    }
    return 0;
}
