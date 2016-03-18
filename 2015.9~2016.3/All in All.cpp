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

string s, t;

int main()
{
    ios::sync_with_stdio(0);
    while (cin >> s >> t) {
        int i = 0;
        for (int j = 0; j < t.length(); ++j) {
            if (s[i] == t[j]) ++i;
            if (i == s.length()) break;
        }
        if (i == s.length()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
