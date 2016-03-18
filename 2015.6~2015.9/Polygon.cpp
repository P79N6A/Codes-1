#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;

int main()
{
    int t, n, k;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        cin >> n >> k;
        ll up = pow(2,k) - (k + 1);
        ll down = pow(2,k);
        ll gcd = __gcd(up, down);
        up /= gcd;
        down /= gcd;
        cout << "Case #" << kase << ": " << up << '/' << down << '\n';
    }
    return 0;
}
