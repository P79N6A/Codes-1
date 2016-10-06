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

int len[3], judge, x, y;
bool ok() {
    for (int i = 0; i < 3; ++i) if (len[i] != x) return 0;
    return 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> x >> y) {
        int ans = 0;
        for (int i = 0; i < 3; ++i) len[i] = y;
        while (!ok()) {
            sort(len, len + 3);
            len[0] = min(x, len[2] + len[1] - 1);
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
