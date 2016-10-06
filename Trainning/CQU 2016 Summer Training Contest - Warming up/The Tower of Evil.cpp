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

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll t, d, h, w;
    cin >> t;
    while (t --) {
        cin >> h >> w >> d;
        if (h <= w) {
            if (d == h) cout << "Yes\n";
            else cout << "No\n";
        }
        else {
            --w;
            int loop = (h - 1) / w;
            int lef = loop % 2;
            h -= (loop / 2) * 2 * w;
            if (!lef && h == d) cout << "Yes\n";
            else if (!lef) cout << "No\n";
            else if (h == w + w - d + 2) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
