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
char s[MAXN];
int num[30];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, need; scanf("%d", &t);
    while (t --) {
        scanf("%s", s);
        scanf("%d", &need);

        int len = strlen(s);
        ll ans = 0;
        int cnt = 0;
        memset(num, 0, sizeof num);
        ll l = 0;
        for (int r = 0; r < len; ++r) {
            int cur = s[r] - 'a';
            ++num[cur];
            if (num[cur] == 1) ++cnt;
            while (cnt == need) {
                ans += len - r;
                int v = s[l++] - 'a';
                --num[v];
                if (num[v] == 0) {
                    --cnt;
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
