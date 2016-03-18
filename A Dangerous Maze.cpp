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

int main()
{
    int t, n;
    for (int kase = scanf("%d", &t); kase <= t; ++kase) {
        scanf("%d", &n);
        int x, sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            sum += abs(x);
            if (x < 0) ++cnt;
        }
        printf("Case %d: ", kase);
        if (cnt == n) {
            printf("inf\n");
            continue;
        }
        int gcd = __gcd(sum, n - cnt);
        printf("%d/%d\n", sum / gcd, (n - cnt) / gcd);
    }
    return 0;
}
