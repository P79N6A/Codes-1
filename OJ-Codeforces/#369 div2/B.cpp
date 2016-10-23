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
const int MAXN = 511;

ll mp[MAXN][MAXN];

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cin >> mp[i][j];
    		if (mp[i][j] == 0) {
    			x = i, y = j;
    		}
    	}
    }
    if (n == 1) cout << 1 << '\n';
    else {
    	int choose = 1;
    	if (x == 1) choose = 0;
    	ll sum = 0, sumx = 0;
    	for (int i = 0; i < n; ++i) {
    		sum += mp[choose][i];
    		sumx += mp[x][i];
    	}
    	mp[x][y] = sum - sumx;
    	if (mp[x][y] < 1) cout << -1 << '\n';
    	else {
    		bool flag = 1;
    		for (int i = 0; i < n; ++i) {
				ll temp = 0;
				for (int j = 0; j < n; ++j) {
					temp += mp[i][j];
				}
				if (temp != sum) {
					flag = 0;
					break;
				}
    		}
    		for (int i = 0; i < n; ++i) {
				ll temp = 0;
				for (int j = 0; j < n; ++j) {
					temp += mp[j][i];
				}
				if (temp != sum) {
					flag = 0;
					break;
				}
    		}
    		ll temp = 0;
    		for (int i = 0; i < n; ++i) {
    			temp += mp[i][i];
    		}
    		if (temp != sum) {
    			flag = 0;
    		}
    		temp = 0;
    		for (int i = 0; i < n; ++i) {
    			temp += mp[n - i - 1][i];
    		}
    		if (temp != sum) {
    			flag = 0;
    		}
    		if (flag) cout << mp[x][y] << '\n';
    		else cout << -1 << '\n';
    	}
    }
    return 0;
}