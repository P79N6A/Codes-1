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
    ll n; cin >> n;
    if (n == 1 || n == 2) {
        cout << -1 << '\n';
        return 0;
    }
    if (n % 2) {
        ll nw = n * n;
        cout << nw / 2 << ' ' << nw / 2 + 1 << '\n';
    }
    else {
        n /= 2;
        ll nw = n * n;
        cout << nw - 1 << ' ' << nw + 1 << '\n';
    }
    return 0;
}
