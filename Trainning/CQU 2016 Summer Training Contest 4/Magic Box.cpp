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
const int MAXN = 11;

int a[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x, y, z, x1, y1, z1;
    while (cin >> x >> y >> z) {
        cin >> x1 >> y1 >> z1;
        for (int i = 1; i <= 6; ++i) cin >> a[i];
        int ans = 0;
        if (x < 0) ans += a[5];
        else if (x > x1) ans += a[6];

        if (y < 0) ans += a[1];
        else if (y > y1) ans += a[2];

        if (z < 0) ans += a[3];
        else if (z > z1) ans += a[4];

        cout << ans << '\n';
    }
    return 0;
}
