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
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0) {
        if (a == b) puts("YES");
        else puts("NO");
        return 0;
    }
    if (c > 0) {
        if (b < a || (b - a) % c) puts("NO");
        else puts("YES");
    }
    else {
        if (b > a || (b - a) % c) puts("NO");
        else puts("YES");
    }
    return 0;
}
