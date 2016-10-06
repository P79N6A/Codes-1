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

int a[111];

int main()
{
    int n;
    while (cin >> n && n) {
        bool flag = 1 - n % 2;
        for (int i = 0; i < n; ++i) cin >> a[i];
        int sum = a[0] + a[n - 1];
        for (int i = 1; i < n / 2; ++i) {
            if (a[i] + a[n - i - 1] != sum) {
                flag = 0;
                break;
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
