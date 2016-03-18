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
const int MAXN = 1e6 + 111;
int mp[50][50];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mp[i][j];
    int ans = 0, sumc, sumr;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            sumc = sumr = 0;
            for (int k = 0; k < n; ++k)
            {
                sumc += mp[k][j];
                sumr += mp[i][k];
            }
            if (sumc > sumr) ++ans;
        }
    cout << ans << '\n';
	return 0;
}

