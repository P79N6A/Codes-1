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
    int t; cin >> t;
    while (t --) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        int ansl = -1, ansr = -1;
        for (int i = 0; i <= 1000; ++i) {
            if ((c - a * i) % b == 0) {
                ansl = i;
                ansr = (c - a * i) / b;
                if ((a == b && (a + b) % 2 ) || (a != b && ansl % 2 || ansr % 2)) {
                    ansl = ansr = -1;
                    continue;
                }
                break;
            }
        }
        if (ansl != -1) cout << ansl << ' ' << ansr << '\n';
        else cout << "Impossible\n";
    }
    return 0;
}
