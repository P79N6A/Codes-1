#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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
    string s;
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
    	if (i < n - 2 && s.substr(i, 3) == "ogo") {
    		cout << "***";
    		for (int j = i + 3; j < n - 1; j += 2) {
    			if (s[j] == 'g' && s[j + 1] == 'o') {
    				i += 2;
    			}
    			else break;
    		}
    		i += 2;
    	}
    	else cout << s[i];
    }
    return 0;
}