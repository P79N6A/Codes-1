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
const int MAXN = 3e3 + 111;

string mRept(string s) {
    string ret = "0";
    vector<string> temp;
    int cnt = 0, p = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') ++cnt;
        else --cnt;
        if (cnt == 0) {
            temp.push_back(mRept(s.substr(p + 1, i - 1 - (p + 1) + 1)));
            p = i + 1;
        }
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i) ret += temp[i];
    return ret + "1";
}

string s, s2;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; cin >> t;
    while (t --) {
        cin >> s >> s2;
        if (mRept(s) == mRept(s2)) {
            cout << "same\n";
        }
        else cout << "different\n";
    }
    return 0;
}
