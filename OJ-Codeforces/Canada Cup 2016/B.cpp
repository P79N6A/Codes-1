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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char *p = "fedabc";

int getpos(char s) {
	for (int i = 0; i < 6; ++i) {
		if (s == p[i]) return i + 1;
	}
	return 0;
}

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    string s;
    while (cin >> s) {
	    ll row = 0;
	    for (int i = 0; i < s.length() - 1; ++i) {
	    	row *= 10;
	    	row += s[i] - '0';
	    }
	    int pos = getpos(s.back());
	    ll ans = (row / 4) * (12 + 4);
	    if (row / 4 > 0) ans -= 3;
	    if (row % 4) {
	    	ll lef = row % 4;
	    	if (row / 4 > 0) ans += 3;
	    	if (lef == 2) {
	    		ans += 12 + 1;
	    	}
	    	else ans += 6;
	    }
	    cout << ans - (6 - pos) << '\n';
	}
    return 0;
}