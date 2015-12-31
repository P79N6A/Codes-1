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
const int MAXN = 1e4 + 111;

int main()
{
    string s;
    int t, l, r, k;
    cin >> s >> t;
    while (t --)
    {
        cin >> l >> r >> k;
        l--, r--;
        int len = r - l + 1;
        k %= len;
        string templ, tempr;
        for (int i = l; i <= r - k; ++i)
        {
            tempr += s[i];
        }
        for (int i = r - k + 1; i <= r; ++i)
        {
            templ += s[i];
        }
        string temp = templ + tempr;
        for (int i = l; i <= r; ++i)
        {
            s[i] = temp[i - l];
        }
    }
    cout << s << '\n';
    return 0;
}
