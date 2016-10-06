#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x7f7f7f7f, MAXN = 3e5 + 111;
int a[MAXN], l[MAXN], r[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        l[i] = r[i] = i;
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; ++i)
    {
        while(l[i] - 1 >= 1 && a[l[i]-1]%a[i]==0)
            l[i]=l[l[i]-1];
    }
    for (int i = n - 1; i >= 1; --i)
    {
        while(r[i] + 1 <= n && a[r[i]+1]%a[i]==0)
            r[i]=r[r[i]+1];
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i)
         mx = max(mx, r[i] - l[i]);
    set<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (r[i] - l[i] == mx)
        {
            ans.insert(l[i]);
        }
    }
    cout << ans.size() << ' ' << mx << '\n';
    set<int>::iterator it;
    for (it = ans.begin(); it != ans.end(); ++it)
    {
        if (it != ans.begin()) cout << ' ';
        cout << *it;
    }
    cout << '\n';
    return 0;
}

