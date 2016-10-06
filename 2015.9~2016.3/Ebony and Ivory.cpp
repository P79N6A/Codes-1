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
    int a, b, c;
    while (cin >> a >> b >> c) {
        bool flag = 0;
        for (int i = 0; i * a <= c; ++i) {
            int lef = c - i * a;
            if (lef % b == 0) {
                flag = 1;
                break;
            }
        }

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
