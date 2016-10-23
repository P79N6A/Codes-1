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
const int MAXN = 111;

bool mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n;
    while (cin >> n) {
    	memset(mp, 0, sizeof mp);
    	for (int i = 0; i < n / 2; ++i) {
    		for (int j = 0; j < n / 2 - i; ++j) {
    			mp[i][j] = true;
    			mp[i][n - j - 1] = true;
    			mp[n - i - 1][j] = true;
    			mp[n - i - 1][n - j - 1] = true;
    		}
    	}
    	int odd = -1, even = 0;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			if (mp[i][j]) cout << (even += 2) << ' ';
    			else cout << (odd += 2) << ' ';
    		}
    		cout << '\n';
    	}
    }
    return 0;
}