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

double pi = acos(-1);

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    double n, r, R;
    cin >> n >> R >> r;
    int x = pi / (asin(r / (R - r))) + 1e-7;
    if (x < 0) x = r <= R;
    if (x >= n) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
