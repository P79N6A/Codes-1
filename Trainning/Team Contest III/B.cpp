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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2111;

char mp[3][MAXN];

int main()
{
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    int n, m;
    char more, les;
    scanf("%d%d", &n, &m);
    if (n > m) {
        more = '@', les = '.';
    }
    else {
        more = '.', les = '@';
        swap(n, m);
    }
    int len = 0;
    mp[0][len++] = les;
    for (int i = 0; i < n; ++i) {
        mp[0][len++] = more;
        mp[0][len++] = les;
    }
    for (int i = 0; i < len; ++i) {
        mp[1][i] = les;
    }
    --m;
    for (int i = 1; i <= m; ++i) {
        mp[1][2 * i - 1] = more;
    }
    printf("%d %d\n", 2, len);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < len; ++j) {
            putchar(mp[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
