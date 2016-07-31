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
const int MAXN = 1e5 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, x; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int one = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (x % 2) {
                ++one;
                --x;
            }
            sum += x;
        }
        sum /= 2;
        int ans = 0;
        if (one == 0) {
            ans = sum * 2;
        }
        else {
            int give = sum / one;
            ans = give * 2 + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
