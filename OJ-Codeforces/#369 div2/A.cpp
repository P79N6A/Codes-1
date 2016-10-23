#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstring>
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

string s[1005];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n; cin >> n;
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> s[i];
    	if (flag) continue;
    	if (s[i][0] == s[i][1] && s[i][0] == 'O') {
    		flag = 1, s[i][0] = s[i][1] = '+';
    		continue;
    	}
    	if (s[i][3] == s[i][4] && s[i][3] == 'O') flag = 1, s[i][3] = s[i][4] = '+';
    }
    cout << (flag? "YES" : "NO") << '\n';
    if (flag) {
    	for (int i = 0; i < n; ++i) cout << s[i] << '\n';
    }
    return 0;
}