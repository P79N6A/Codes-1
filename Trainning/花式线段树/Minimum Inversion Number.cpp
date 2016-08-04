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
const int MAXN = 5e3 + 111;

int sum[MAXN], n;
int a[MAXN];

int getsum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += sum[x];
        x -= x & (-x);
    }
    return ret;
}

void add(int x) {
    while (x <= n) {
        sum[x] += 1;
        x += x & (-x);
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++a[i];
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += getsum(a[i]);
            add(a[i]);
        }
        int temp = ans;
        for (int i = 0; i < n - 1; ++i) {
            temp += -(a[i] - 1) + (n - a[i]);
            ans = min(ans, temp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
