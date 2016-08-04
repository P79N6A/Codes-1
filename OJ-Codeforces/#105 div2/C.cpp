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
const int MAXN = 111;

int ans[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, a, b;
    while (cin >> n >> a >> b) {
        ans[0] = 1;
        int sum = 1;
        if (n > 1 && b == 0 && n - a == 1) {
            puts("-1");
            continue;
        }
        if (b == 0) {
            for (int i = 0; i < n - a; ++i) ans[i] = 1;
            for (int i = n - a; i < n; ++i) ans[i] = ans[i - 1] + 1;
        }
        else {
            for (int i = 1; i <= b; ++i) ans[i] = sum + 1, sum += ans[i];
            for (int i = b + 1; i < b + 1 + a; ++i) ans[i] = ans[i - 1] + 1;
            for (int i = b + 1 + a; i < n; ++i) ans[i] = ans[i - 1];
        }
        for (int i = 0; i < n; ++i) cout << ans[i] << (i == n - 1? '\n' : ' ');
    }
    return 0;
}
