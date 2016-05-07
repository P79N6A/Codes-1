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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;

int dpl[MAXN][20], dph[MAXN][20], a[MAXN];

int getMax(int l, int r) {
    int k = log2(r - l + 1);
    return max(dph[l][k], dph[r - (1 << k) + 1][k]);
}

int getMin(int l, int r) {
    int k = log2(r - l + 1);
    return min(dpl[l][k], dpl[r - (1 << k) + 1][k]);
}

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            dpl[i][0] = dph[i][0] = a[i];
        }

        for (int j = 1; j < 20; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (i + (1 << j) - 1 <= n) {
                    dpl[i][j] = min(dpl[i][j - 1], dpl[i + (1 << (j - 1))][j - 1]);
                    dph[i][j] = max(dph[i][j - 1], dph[i + (1 << (j - 1))][j - 1]);
                }
                else break;
            }
        }

        int l, r;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &l, &r);
            printf("%d\n", getMax(l, r) - getMin(l, r));
        }
    }
    return 0;
}
