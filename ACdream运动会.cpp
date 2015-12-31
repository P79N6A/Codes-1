#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

bool is[MAXN];
int a[30];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m;
    scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &m);
        memset(is, 0, sizeof is);
        for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            int temp = a[i];
            while (temp <= n)
            {
                is[temp] = 1;
                temp += a[i];
            }
        }
        for (int i = 0; i <= n; ++i)
            if (is[i]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
