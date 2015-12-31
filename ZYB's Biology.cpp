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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int main()
{
    string s1, s2;
    int t, n; cin >> t;
    while (t --)
    {
        cin >> n >> s1 >> s2;
        bool flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s1[i] == 'A')
            {
                if (s2[i] != 'U')
                {
                    flag = 1;
                    break;
                }
            }
            else if (s1[i] == 'T')
            {
                if (s2[i] != 'A')
                {
                    flag = 1;
                    break;
                }
            }
            else if (s1[i] == 'C')
            {
                if (s2[i] != 'G')
                {
                    flag = 1;
                    break;
                }
            }
            else if (s2[i] != 'C')
            {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
