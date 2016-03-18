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
    ll a, b;
    while (cin >> a >> b && (a | b)) {
        bool flag = 0;
        while (1) {
            if (a < b) swap(a, b);
            flag = 1 - flag;
            if (b == 0 || a / b > 1 || a == b) {
                if (flag) cout << "Stan";
                else cout << "Ollie";
                break;
            }
            else {
                a = a % b;
            }
        }
        cout << " wins\n";
    }
    return 0;
}
