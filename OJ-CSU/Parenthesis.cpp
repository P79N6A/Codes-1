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
const int MAXN = 1e5 + 111;

int sum[MAXN], num[MAXN];
char s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        scanf("%s", s + 1);
        sum[0] = num[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
            num[i] = num[i - 1] + (sum[i] < 2 ? 1 : 0);
        }
        int l, r;
        while (m --) {
            scanf("%d%d", &l, &r);
            if (l > r) swap(l, r);
            if (s[l] == s[r] || s[l] == ')') puts("Yes");
            else if (num[r - 1] - num[l - 1] > 0) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}
