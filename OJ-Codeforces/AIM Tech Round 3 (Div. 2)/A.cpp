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
    int n, b, d, a;
    scanf("%d%d%d", &n, &b, &d);
    int sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (a > b) continue;
        sum += a;
        if (sum > d) {
            sum = 0;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
