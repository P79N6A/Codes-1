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
const int MAXN = 3e5 + 111;

int a[MAXN];

int main()
{
    int n, m, aa, bb;
    while (cin >> aa >> bb) {
        int cnt = 0;
        n = aa, m = bb;
        while (n || m) {
            if (n == 0) {
                a[cnt++] = 1;
                --m;
            }
            else if (m == 0) {
                a[cnt++] = 0;
                --n;
            }
            else {
                if (cnt == 0) {
                    a[cnt++] = 0;
                    --n;
                }
                else {
                    if (cnt % 2) {
                        a[cnt] = 1 - a[cnt - 1];
                        if (a[cnt] == 0) --n;
                        else --m;
                        ++cnt;
                    }
                    else {
                        a[cnt] = a[cnt - 1];
                        if (a[cnt] == 0) --n;
                        else --m;
                        ++cnt;
                    }
                }
            }
        }
        int l = 0, r = 0;
        for (int i = 0; i < cnt - 1; ++i) {
            if (a[i] == a[i + 1]) ++l;
            else ++r;
        }

        cnt = 0;
        n = aa, m = bb;
        while (n || m) {
            if (n == 0) {
                a[cnt++] = 1;
                --m;
            }
            else if (m == 0) {
                a[cnt++] = 0;
                --n;
            }
            else {
                if (cnt == 0) {
                    a[cnt++] = 1;
                    --m;
                }
                else {
                    if (cnt % 2) {
                        a[cnt] = 1 - a[cnt - 1];
                        if (a[cnt] == 0) --n;
                        else --m;
                        ++cnt;
                    }
                    else {
                        a[cnt] = a[cnt - 1];
                        if (a[cnt] == 0) --n;
                        else --m;
                        ++cnt;
                    }
                }
            }
        }
        int l2 = 0, r2 = 0;
        for (int i = 0; i < cnt - 1; ++i) {
            if (a[i] == a[i + 1]) ++l2;
            else ++r2;
        }
        if (l > l2) cout << l << ' ' << r << '\n';
        else if (l < l2) cout << l2 << ' ' << r2 << '\n';
        else if (r > r2) cout << l2 << ' ' << r2 << '\n';
        else cout << l << ' ' << r << '\n';
    }
    return 0;
}
