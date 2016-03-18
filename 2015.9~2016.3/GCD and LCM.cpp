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

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main()
{
    int a, b;
    while (cin >> a >> b) {
        int g = gcd(a, b);
        cout << g << ' ' << a / g * b << '\n';
    }
    return 0;
}
