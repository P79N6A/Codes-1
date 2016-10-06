#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e5 + 111;
vector<int> son[MAXN];
int n, t;

int dp(int u)
{
    if(son[u].empty()) return 1;
    int k = son[u].size();
    vector<int> b;
    for (int i = 0; i < k; ++i)
        b.push_back(dp(son[u][i]));
    sort(b.begin(), b.end());
    int c = (k * t - 1) / 100 + 1;
    int ans = 0;
    for (int i = 0; i < c; ++i) ans += b[i];
    return ans;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int x;
	while ( cin >> n >> t && (n || t))
	{
	    for (int i = 0; i <= n; ++i) son[i].clear();
	    for (int i = 1; i <= n; ++i)
	    {
	        cin >> x;
	        son[x].push_back(i);
	    }
        cout << dp(0) << '\n';
    }
	return 0;
}


