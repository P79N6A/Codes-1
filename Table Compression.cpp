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

int a[MAXN];
int b[MAXN];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int up = n * m;
    for (int i = 0; i < up; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    int cnt = 0;
    sort(b, b + up);
    int len = unique(b, b + up) - b;
    for (int i = 0; i < up; ++i) {
        int x = lower_bound(b, b + len, a[i]) - b;
        printf("%d", x + 1);
        ++cnt;
        if (cnt < m) {
            printf(" ");
        }
        else {
            printf("\n");
            cnt = 0;
        }
    }
    return 0;
}
