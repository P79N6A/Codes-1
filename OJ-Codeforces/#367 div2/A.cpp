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
#define pr(x) cout << #x << " = " << (x) << " I ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double x, y, a, b, ans = INF, v;
    int n;
    cin >> x >> y >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> v;
        double dx = a - x, dy = b - y;
        ans = min(ans, sqrt(dx * dx + dy * dy) / v);
    }
    printf("%.10f\n", ans);
    return 0;
}
