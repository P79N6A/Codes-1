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
const int MAXN = 1e4 + 111;

int ans1[MAXN], ans2[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    int a, b, c, d;
    while (~scanf("%d%d", &n, &k)) {
        int cnt1 = 0, cnt2 = 0;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (n == 4 || n + 1 > k) printf("-1\n");
        else {
            ans1[cnt1++] = a;
            ans1[cnt1++] = d;
            ans1[cnt1++] = c;
            ans2[cnt2++] = c;
            for (int i = 1; i <= n; ++i) {
                if (i != a && i != b && i != c && i != d) {
                    ans1[cnt1++] = i;
                }
            }
            ans1[cnt1++] = b;
            swap(ans1[2], ans1[3]);
            memcpy(ans2, ans1, sizeof ans1);
            swap(ans2[0], ans2[1]);
            cnt2 = cnt1;
            for (int i = 0; i < cnt1; ++i) {
                printf("%d", ans1[i]);
                if (i != cnt1 - 1) putchar(' ');
                else putchar('\n');
            }
            for (int j = 3; j < cnt2; ++j) {
                printf("%d", ans2[j]);
                putchar(' ');
            }
            for (int i = 2; i >= 0; --i) {
                printf("%d", ans2[i]);
                if (i != 0) putchar(' ');
                else putchar('\n');
            }
        }
    }
    return 0;
}
