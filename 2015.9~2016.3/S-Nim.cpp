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
const int MAXN = 111;

int s[MAXN], sg[10011];
int k, l, h[MAXN];
bool mark[10011];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int m;
    while (~scanf("%d", &k) && k)
    {
        for (int i = 0; i < k; ++i) scanf("%d", &s[i]);
        scanf("%d", &m);

        for (int i = 1; i <= 10000; ++i)
        {
            memset(mark, 0, sizeof mark);
            for (int j = 0; j < k; ++j)
                if (i - s[j] >= 0) mark[sg[i - s[j]]] = 1;
            for (int j = 0; ; ++j)
                if (!mark[j])
                {
                    sg[i] = j;
                    break;
                }
        }

        while (m --)
        {
            scanf("%d", &l);
            for (int i = 0; i < l; ++i)
                scanf("%d", &h[i]);

            int sum = 0;
            for (int i = 0; i < l; ++i)
                sum ^= sg[h[i]];
            if (sum) printf("W");
            else printf("L");
        }
        puts("");
    }
    return 0;
}
