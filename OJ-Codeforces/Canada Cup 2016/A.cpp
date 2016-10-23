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

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '<') ++ans;
    	else break;
    }
    for (int i = n - 1; i >= 0; --i) {
    	if (s[i] == '>') ++ans;
    	else break;
    }
    cout << ans << '\n';
    return 0;
}