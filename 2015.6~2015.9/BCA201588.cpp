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
const int MAXN = 1e4 + 111;
int num[MAXN];

int main()
{
    int n;
    while (cin >> n)
    {
        int x;
        memset(num, 0, sizeof num);
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            ++num[x];
        }
        int ans = -1;
        for (int i = 0; i < MAXN - 110; ++i)
        {
            if (num[i] * 2 > n)
            {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
	return 0;
}

