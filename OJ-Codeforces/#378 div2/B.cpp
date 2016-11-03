#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

int l[MAXN], r[MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n; scanf("%d", &n);
    int lsum = 0, rsum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        lsum += l[i];
        rsum += r[i];
    }
    int mx = abs(lsum - rsum);
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        int nmx = abs(lsum - l[i] + r[i] - (rsum - r[i] + l[i]));
        if (nmx > mx) {
            mx = nmx;
            pos = i;
        }
    }
    printf("%d\n", pos);
    return 0;
}