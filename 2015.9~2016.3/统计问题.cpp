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
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 111;

int f[MAXN], h[MAXN], z[MAXN];

int main()
{
    int c, n; cin >> c;
    f[1] = 3;
    h[1] = 2;
    z[1] = 1;
    for (int i = 2; i <= 22; ++i) {
        z[i] = f[i - 1];
        h[i] = 2 * z[i - 1] + h[i - 1];
        f[i] = z[i] + h[i];
    }
    while (c --) {
        cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}
