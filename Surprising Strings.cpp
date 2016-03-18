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

map<string, bool> mp;

int main()
{
    string s;
    while (cin >> s && s != "*") {
        bool is = 1;
        for (int i = 1; i < s.length() && is; ++i) {
            mp.clear();
            string t;
            for (int j = 0; j + i < s.length(); ++j) {
                t.push_back(s[j]);
                t.push_back(s[j + i]);
                if (mp[t]) {
                    is = 0;
                    break;
                }
                mp[t] = 1;
                t.clear();
            }
        }
        cout << s << " is ";
        if (!is) cout << "NOT ";
        cout << "surprising.\n";
    }
    return 0;
}
