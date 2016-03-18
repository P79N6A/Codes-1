#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#define l(u) (u<<1)
#define r(u) (u<<1|1)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1
#define bug puts("I am bug")
#define xy(x, y) printf("(%d %d)\n", x, y)
typedef long long ll;
using namespace std;

int main() {
    int t; cin >> t;
    while (t --)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i <= 12; ++i)
        {
            if (12 % i == 0)
            {
                for (int j = 0; j < i; ++j)
                {
                    bool flag = 0;
                    for (int k = j; k < 12; k += i)
                    {
                        if (s[k] == 'O')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        ++ans;
                        break;
                    }
                }
            }
        }
        cout << ans;
        for (int i = 12; i >= 1; --i)
        {
            if (12 % i == 0)
            {
                for (int j = 0; j < i; ++j)
                {
                    bool flag = 0;
                    for (int k = j; k < 12; k += i)
                    {
                        if (s[k] == 'O')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        cout << ' ' << 12 / i << 'x' << i;
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
