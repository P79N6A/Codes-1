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
const int MAXN = 1e6 + 111;

int main()
{
    string s;
    cin >> s;
    int pp = -1, pe = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.') pp = i;
        if (s[i] == 'e') pe = i;
    }
    if (pp == -1) pp = pe;
    string ss;
    bool first = 1;
    for (int i = 0; i < pp; ++i) {
        if (first && s[i] == '0') continue;
        ss.push_back(s[i]);
        first = 0;
    }
    for (int i = pe - 1; i > pp; --i) {
        if (s[i] == '0') ;
        else {
            for (int j = pp; j <= i; ++j) {
                ss.push_back(s[j]);
            }
            break;
        }
    }
    if (isdigit(s[pe + 1]) || (s[pe + 2] == '0')) {
        for (int i = s.length() - 1; i > pe; --i) {
            if (s[i] != '0') {
                for (int j = pe; j <= i; ++j) {
                    ss.push_back(s[j]);
                }
                break;
            }
        }
    }
    else {
        for (int i = pe; i < s.length(); ++i) ss.push_back(s[i]);
    }
    //pr(ss)

    int num = 0;
    pp = -1, pe = -1;
    for (int i = 0; i < ss.length(); ++i) {
        if (ss[i] == '.') pp = i;
        if (ss[i] == 'e') pe = i;
    }
    string ans;
    if (pp == -1) {
        for (int i = pe - 1; i >= 0; --i) {
            if (ss[i] == '0') ++num;
            else {
                for (int j = 0; j <= i; ++j) {
                    if (ss[j] == '+') continue;
                    ans.push_back(ss[j]);
                }
                break;
            }
        }
    }
    else {
        for (int i = 0; i < pe; ++i) {
            if (ss[i] == '+') continue;
            ans.push_back(ss[i]);
        }
    }
    ll number2 = 0;
    for (int i = pe + 1; i < ss.length(); ++i) {
        if (isdigit(ss[i])) {
            number2 *= 10;
            number2 += ss[i] - '0';
        }
    }
    if (ss[pe + 1] == '-') {
        number2 = -number2;
    }
    else number2 += num;
    cout << ans << "e" << number2 << '\n';
    return 0;
}
