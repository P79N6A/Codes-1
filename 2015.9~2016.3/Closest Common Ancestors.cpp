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
#define rson m + 1, r, rt << 1 | 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 911;

vector<int> G[MAXN];
int appear[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n))
    {
        int u, num, v, q;
        for (int i = 1; i <= n; ++i) G[i].clear(), appear[i] = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d:(%d)", &u, &num);
            for(int j = 0; j < num; ++j)
            {
                scanf("%d", &v);
                G[u].push_back(v);
            }
        }
        scanf("%d", &q);
        while (q --)
        {
            scanf("(%d %d)", &u, &v);
        }
    }
    return 0;
}
