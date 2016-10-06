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

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, a, b; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        int in = 0, out = 0;
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &a, &b);
            if (a == 1 || b == 1) ++in;
        }
        out = n - in - 1;
        if (in == 1 || (in % 2 && out % 2 == 0) || (in % 2 == 0 && out % 2))
            printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
