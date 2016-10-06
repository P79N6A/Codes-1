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

string s, p;
int nxt[1111];

int kmp() {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < p.length();) {
        while (k != -1 && p[i] != p[k]) k = nxt[k];
        nxt[++i] = ++k;
    }

    int ret = 0;
    int i = 0, j = 0;
    while (i < s.length()) {
        while (j != -1 && s[i] != p[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == p.length()) {
            ++ret;
            j = 0;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    while (cin >> s && s != "#") {
        cin >> p;
        cout << kmp() << '\n';
    }
    return 0;
}
