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

char a[30], b[30];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        scanf("%s%s", a + 1, b + 1);
        if ((a[1] == '<' && b[1] == '^') ||
            (a[1] == '>' && b[m] == '^') ||
            (a[n] == '<' && b[1] == 'v') ||
            (a[n] == '>' && b[m] == 'v')) {
                printf("NO\n");
            }
        else printf("YES\n");
    }
    return 0;
}
