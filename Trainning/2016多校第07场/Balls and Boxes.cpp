/*
  满足二项分布。。。。。。
 */
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
    ll n, m;
    while (cin >> n >> m && (n | m)) {
        ll up = n * (m - 1);
        ll down = m * m;
        ll gcd = __gcd(up, down);
        cout << up / gcd << '/' << down / gcd << '\n';
    }
    return 0;
}
