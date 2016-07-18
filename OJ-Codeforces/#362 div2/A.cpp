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
    ll t, x, s;
    while(cin >> t >> s >> x) {
        ll lef = x - t;
        if (lef >= 0 && (lef % s == 0 || (lef / s > 0 && lef % s == 1))) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
