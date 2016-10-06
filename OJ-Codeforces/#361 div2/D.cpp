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
#define root 0, n - 1, 1
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e5 + 111;

int mx[MAXN][20], mi[MAXN][20];
int a[MAXN], b[MAXN], n;
int mm[MAXN];

void init() {
    mm[0] = -1;
    for(int i = 1; i <= n;i++)
    {
        mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
        mx[i][0] = a[i];
        mi[i][0] = b[i];
    }
    //for (int i = 0; i <= n; ++i) cout << mm[i] << '\n';
    for(int j = 1; j <= mm[n];j++)
        for(int i = 1;i + (1 << j) - 1 <= n; ++i) {
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
        }
}

int getMax(int l, int r) {
    int k = mm[r - l + 1];
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

int getMin(int l, int r) {
    int k = mm[r - l + 1];
    return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    init();
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > b[i]) continue;
        int l = i, r = n;
        int mr = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            int MX = getMax(i, mid);
            int MI = getMin(i, mid);
            if (MX <= MI) {
                if (MX == MI)
                    mr = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        l = i, r = n - 1;
        int ml = mr;
        while (l <= r) {
            int mid = l + r >> 1;
            int MX = getMax(i, mid);
            int MI = getMin(i, mid);
            if (MX >= MI) {
                if (MX == MI)
                    ml = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (mr != -1) ans += mr - ml + 1;
    }
    printf("%I64d\n", ans);
    return 0;
}
