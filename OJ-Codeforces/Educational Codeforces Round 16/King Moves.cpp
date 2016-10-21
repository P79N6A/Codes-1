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

int dir[][2] = {1, 1, -1, -1, 1, -1, -1, 1, 0, 1, 1, 0, 0, -1, -1, 0};

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    string s;
    cin >> s;
    int x = s[0] - 'a', y = s[1] - '1';
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
    	int nx = x + dir[i][0], ny = y + dir[i][1];
    	//pr(nx) pr(ny)
    	if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
    		++ans;
    	}
    }
    cout << ans << '\n';
    return 0;
}