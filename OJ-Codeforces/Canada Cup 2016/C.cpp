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
const int MAXN = 31;

bool vis[MAXN];
char ans[2][MAXN];
int dir[][2] = {-1, -1, 1, 1, 1, 0, -1, 0};

int main()
{
    #ifdef GooZy
    freopen("/Users/apple1/Desktop/in.txt", "r", stdin);
    //freopen("/Users/apple1/Desktop/out.txt","w",stdout);
    #endif
    string s;
    cin >> s;
    char u = 0, v = 0;
    bool cant = 0;
    for (int i = 0; i < 27; ++i) {
    	int cur = s[i] - 'A';
    	if (vis[cur]) {
    		u = s[i - 1];
    		v = cur + 'A';
    		if (u == v) cant = 1;
    	}
    	vis[cur] = true;
    }
    if (cant) cout << "Impossible\n";
    else {
    	bool first = 1;
    	int len = 0;
    	for (int i = 0; i < 13; ++i) {
    		if (s[len] == v && !first) {
    			--i;
    			++len;
    			continue;
    		}
    		if (s[len] == v && first) {
    			first = 0;
    		}
    		ans[0][i] = s[len++];
    	}
    	for (int i = 12; i >= 0; --i) {
    		if (s[len] == v && !first) {
    			++i;
    			++len;
    			continue;
    		}
    		if (s[len] == v && first) {
    			first = 0;
    		}
    		ans[1][i] = s[len++];
    	}
    	while (1) {
    		bool ok = 0;
    		for (int i = 0; i < 2; ++i) {
    			for (int j = 0; j < 13; ++j) {
    				if (ans[i][j] == u) {
    					for (int k = 0; k < 4; ++k) {
    						int nx = i + dir[k][0], ny = j + dir[k][1];
    						if (0 <= nx && nx < 2 && 0 <= ny && ny < 13) {
    							if (ans[nx][ny] == v) {
    								ok = 1;
    								break;
    							}
    						}
    					}
    				}
    			}
    		}
    		if (ok) break;

    		char temp = ans[0][12];
    		for (int i = 12; i > 0; --i) 
    			ans[0][i] = ans[0][i - 1];
    		ans[0][0] = ans[1][0];
    		for (int i = 0; i < 12; ++i)
    			ans[1][i] = ans[1][i + 1];
    		ans[1][12] = temp;
    	}
    	cout << ans[0] << '\n' << ans[1] << '\n';
    }
    return 0;
}