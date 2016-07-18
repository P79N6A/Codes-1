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

string change(string s) {
    for (int i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i]);
        if (s[i] == 'p') {
            s[i] = 'b';
        }
        else if (s[i] == 'e') {
            s[i] = 'i';
        }
    }
    return s;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t;
    string s1, s2;
    cin >> t;
    while (t --) {
        cin >> s1 >> s2;
        if (change(s1) == change(s2)) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
    return 0;
}
