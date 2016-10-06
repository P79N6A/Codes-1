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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2e4 + 111;

int nxt[MAXN];

int MR(string &s, int l) {
    int i = 0, j = 1, k = 0;
    while (i < l && j < l) {
        k = 0;
        while (s[i + k] == s[j + k]) ++k;
        if (k == l) return min(i, j);
        if (s[i + k] < s[j + k]) i = max(j + 1, i + k + 1);
        else j = max(i + 1, j + k + 1);
    }
    return min(i, j);
}

void getNext(string &p) {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < p.length();) {
        while (k != -1 && p[i] != p[k]) k = nxt[k];
        nxt[++i] = ++k;
    }
}

int kmp(string &s, string &p) {
    getNext(p);
    int i = 0, j = 0;
    int ret = 0;
    while (i < s.length()) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == p.length()) {
            if (i - j < j) ret = max(ret, i - j);
            else break;
            j = nxt[j];
        }
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, t; cin >> t;
    string s;
    while(t --) {
        cin >> n >> s;
        string rs = s;
        for (int i = 0; i < n; ++i) rs[i] = s[n - i - 1];
        s += s, rs += rs;

        int ans1 = MR(s, n), ans2 = MR(rs, n);
        string s1 = s.substr(ans1, n);
        string s2 = rs.substr(ans2, n);

        ans2 = n - kmp(rs, s2);
        ++ans1;

        if (s1 > s2) {
            cout << ans1 << ' ' << 0 << '\n';
        }
        else if (s2 > s1) {
            cout << ans2 << ' ' << 1 << '\n';
        }
        else {
            if (ans1 <= ans2) cout << ans1 << ' ' << 0 << '\n';
            else cout << ans2 << ' ' << 1 << '\n';
        }
    }
    return 0;
}
