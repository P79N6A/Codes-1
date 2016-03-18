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
const int MAXN = 5e5 + 111;

ll ans;
int a[MAXN], n, b[MAXN];

void mergeArray(int *a, int l, int m, int r) {
    for (int i = l; i <= m; ++i) b[i] = a[i];
    for (int i = m + 1; i <= r; ++i) b[r + m + 1 - i] = a[i];
    int i = l, j = r, len = l;
    while (i != j) {
        if (b[i] > b[j]) {
            a[len++] = b[j--];
            ans += m - i + 1;
        }
        else {
            a[len++] = b[i++];
        }
    }
    a[len++] = b[i];
}

void mergeSort(int *a, int l, int r) {
    if (l == r) return;
    else {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeArray(a, l, m, r);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        ans = 0;
        mergeSort(a, 0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
