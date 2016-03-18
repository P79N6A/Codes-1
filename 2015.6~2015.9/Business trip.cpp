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
int a[13];

int main()
{
    int k, ans = 0; cin >> k;
    for (int i = 1; i < 13; ++i)
        cin >> a[i];
    sort(a + 1, a + 13);
    if (ans == k)
    {
        cout << 0 << endl;
    }
    else
    {
        bool flag = 0;
        int month = 0;
        for (int i = 12; i >= 1; --i)
        {
            month += 1;
            ans += a[i];
            if (ans >= k)
            {
                flag = 1;
                break;
            }
        }
        if (flag) cout << month << '\n';
        else cout << -1 << '\n';
    }
	return 0;
}

