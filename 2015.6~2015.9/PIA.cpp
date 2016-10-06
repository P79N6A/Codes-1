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
int num[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> num[i];
	for(int i = 0; i < n; ++i)
	{
        if(i == 0) cout << num[i + 1] - num[i] << ' ' << num[n - 1] - num[i] << '\n';
        else if( i == n - 1) cout << num[i] - num[ i - 1] << ' ' << num[i] - num[0] << '\n';
        else cout << min(num[i] - num[i - 1], num[i + 1] - num[i]) << ' ' << max(num[n - 1] - num[i], num[i] - num[0]) <<'\n';
    }
	return 0;
}


