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
const int MAXN = 2e5 + 111;
int x[MAXN];
int n, k, a, m;

int place(int l, int r)
{
    return (r - l + 2) / a;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	cin >> n >> k >> a >> m;
	for(int i = 1; i <= m; ++i) cin >> x[i];
    int ans = -1;
    for(int i = 1; i <= m; ++i)
    {
        if(place(
    }
	return 0;
}


