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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int lefa = a - x, lefb = b - y, lefc = c - z;
    int sum = 0;
    if (lefa < 0) sum -= lefa, lefa = 0;
    if (lefb < 0) sum -= lefb, lefb = 0;
    if (lefc < 0) sum -= lefc, lefc = 0;
    int form = lefa / 2 + lefb / 2 + lefc / 2;
    if (form >= sum) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
