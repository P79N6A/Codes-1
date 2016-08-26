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
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int x, y;
    cin >> x >> y;
    if (x < 0 && y < 0) {
        cout << x + y << ' ' << 0 << ' ' << 0 << ' ' << x + y << '\n';
    }
    else if (x < 0 && y > 0) {
        cout << x - y << ' ' << 0 << ' ' << 0 << ' ' << y - x << '\n';
    }
    else if (x > 0 && y > 0) {
        cout << 0 << ' ' << x + y << ' ' << x + y << ' ' << 0 << '\n';
    }
    else {
        cout << 0 << ' ' << y - x << ' ' << x - y << ' ' << 0 << '\n';
    }
    return 0;
}
