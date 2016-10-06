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
const int MAXN = 21;

string ss, s, s2;

int parse(int base, string &s) {
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        ret *= base;
        if (isdigit(s[i])) ret += s[i] - '0';
        else ret += s[i] - 'A' + 10;
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    cin >> ss;
    int len = ss.find(':');
    s = ss.substr(0, len);
    s2 = ss.substr(len + 1, ss.size() - len);
    int mx = 0;
    for (int i = 0; i < ss.length(); ++i) {
        if (isalpha(ss[i])) {
            mx = max(mx, ss[i] - 'A' + 10);
        }
        else if (isdigit(ss[i])) {
            mx = max(mx, ss[i] - '0');
        }
    }
    bool flag = 0;
    int i;
    vector<int> ans;
    for (i = mx + 1; i <= 100; ++i) {
        int l = parse(i, s), r = parse(i, s2);
        if (l < 24 && r < 60) {
            ans.push_back(i);
            flag = 1;
        }
        else break;
    }
    if (!flag) {
        cout << 0 << '\n';
    }
    else {
        if (i == 101) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
