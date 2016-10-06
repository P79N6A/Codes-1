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

int num[3];

void ok(int a, int b, int c, char ans) {
    if (num[b] && num[c]) cout << ans;
    else if (num[a] && (num[b] > 1 || num[c] > 1)) cout << ans;
    else if (!num[b] && !num[c] && num[a]) cout << ans;
}

int main()
{
    int n;
    string s;
    while (cin >> n >> s) {
        memset(num, 0, sizeof num);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') ++num[0];
            if (s[i] == 'G') ++num[1];
            if (s[i] == 'R') ++num[2];
        }

        ok(0, 1, 2, 'B');
        ok(1, 0, 2, 'G');
        ok(2, 0, 1, 'R');

        cout << '\n';
    }
    return 0;
}
