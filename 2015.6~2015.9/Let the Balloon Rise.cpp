#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, mx;
    string s;
    while (cin >> n && n)
    {
        map<string, int> mp;
        string ans;
        mx = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            ++mp[s];
            int temp = mp[s];
            if (temp > mx)
            {
                mx = temp;
                ans = s;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
