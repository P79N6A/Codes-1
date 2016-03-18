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
#define rson m + 1, r, rt << 1 s 1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int l[MAXN], r[MAXN];
char s[MAXN];

int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i)
    {
        if (s[i - 1] == '0') l[i] += l[i - 1] + 1;
        else l[i] = l[i - 1];
    }
    for (int i = len; i >= 1; --i)
    {
        if (s[i] == '1') r[i] += r[i + 1] + 1;
        else r[i] = r[i + 1];
    }
    if (l[len] == 0)
    {
        printf("%d\n", len);
        goto ed;
    }
    for (int i = 1; i <= len; ++i)
    {
        if (l[i] == r[i])
        {
            printf("%d\n", i - 1);
            break;
        }
    }
    ed:
    return 0;
}
