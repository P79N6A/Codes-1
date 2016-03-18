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
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;
int has[111], n, m, k, a, b, c, d, place[111];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, kase = 0; cin >> t;
    while (t --)
    {
        memset(has, 0, sizeof has);
        int cnt = 0, a = 1, b = 2, c = 3, ans = INF;
        vector<int> v;
        cin >> n >> m >> k;
        for (int i = 1; i <= min(3, n); ++i)
        {
            if (!has[i])
            {
                has[i] = 1;
                place[i] = i;
                v.push_back(i);
                ++cnt;
                if (cnt == k)
                {
                    ans = place[v[cnt - 1]] - place[v[0]] + 1;
                    goto label;
                }
            }
        }
        for (int i = 4; i <= n; ++i)
        {
            int d = (a + b + c) % m + 1;
            a = b; b = c; c = d;
            if (d <= k && !has[d])
            {
                has[d] = 1;
                ++cnt;
                place[d] = i;
                v.push_back(d);
            }
            else if(d <= k)
            {
                if (cnt != k)
                {
                    place[d] = i;
                    for (auto it = v.begin(); it != v.end(); ++it)
                    {
                        if (*it == d)
                        {
                            v.erase(it);
                            break;
                        }
                    }
                    v.push_back(d);
                }
                else
                {
                    ans = min(ans, place[v[cnt - 1]] - place[v[0]] + 1);
                    place[d] = i;
                    for (auto it = v.begin(); it != v.end(); ++it)
                    {
                        if (*it == d)
                        {
                            v.erase(it);
                            break;
                        }
                    }
                    v.push_back(d);
                }
            }
        }
        label:
        cout << "Case " << ++kase << ": ";
        if (cnt == k)
        {
            cout << ans << '\n';
        }
        else cout << "sequence nai\n";
    }
    return 0;
}
