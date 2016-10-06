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
const int MAXN = 20;

char str[MAXN];

bool can() {
    for (int i = 0; i < 12; ++i) {
        if (str[i] == 'o') return 1;
    }
    return 0;
}

int getans(int total) {
    if (!can()) return total;
    int mi = total, l, r;
    for (int i = 0; i < 11; ++i) {
        if (str[i] == 'o' && str[i + 1] == 'o') {
            l = r = total;
            if (i - 1 >= 0 && str[i - 1] == '-') {
                str[i - 1] = 'o';
                str[i] = '-';
                str[i + 1] = '-';
                l = getans(total - 1);
                str[i - 1] = '-';
                str[i] = 'o';
                str[i + 1] = 'o';
            }
            if (i + 2 < 12 && str[i + 2] == '-') {
                str[i + 2] = 'o';
                str[i + 1] = '-';
                str[i] = '-';
                r = getans(total - 1);
                str[i + 2] = '-';
                str[i + 1] = 'o';
                str[i] = 'o';
            }
            mi = min(mi, min(l, r));
        }
    }
    return mi;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    while (n --) {
        scanf("%s", str);
        int total = 0;
        for (int i = 0; i < 12; ++i) {
            if (str[i] == 'o') ++total;
        }
        printf("%d\n", getans(total));
    }
    return 0;
}
