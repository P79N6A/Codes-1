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
const int MAXN = 1e3 + 111;

int num[MAXN * MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int len = s.length();
    set<string> st;
    len /= 2;
    for (int i = 1; i <= len; ++i) {
        int up = s.length() - i + 1;
        for (int j = 0; j < up; j += i) {
            st.insert(s.substr(j, i));
        }
    }
    for (int i = 1; i <= len; ++i) {
        int up = s.length() - i + 1;
        for (int j = 0; j < up; j += i) {
            string subs = s.substr(j, i);
            int tol = 0;
            while (st.count(subs)) {
                ++tol;
                subs += subs;
            }
            ++num[tol];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1e6; ++i) {
        if (num[i] > 1) {
            //pr(num[i])
            //pr(i)
            ans += num[i] * (num[i] - 1) / 2;
        }
    }
    cout << ans << '\n';
    return 0;
}
