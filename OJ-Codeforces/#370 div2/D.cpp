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
const int offset = 1e5;

ll dp[2][offset << 2];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    int cur = 0;
    dp[cur][0 + offset] = 1;
    for (int i = 1; i <= t; ++i) {
        cur = !cur;
    }
    return 0;
}
