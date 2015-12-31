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
    int n;
    while (cin >> n)
    {
        vector<int> ans, temp;
        int n2 = n;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                for (int j = i; j <= n; ++j)
                {
                    if (n2 % j == 0)
                    {
                        n2 /= j;
                        temp.push_back(j);
                    }
                    else break;
                }
                n2 = n;
                if (temp.size() > ans.size()) ans = temp;
                temp.clear();
            }
        }
        if (ans.size() == 0 && n != 1) ans.push_back(n);
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i];
            if (i != ans.size() - 1) cout << '*';
        }
        cout << '\n';
    }
    return 0;
}
