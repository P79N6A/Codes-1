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

int main()
{
    int n, k, i = 0, j = 0;
    while (cin >> n >> k)
    {
        int mx = ceil((double)n / 2), mi = n / 2;
        if (mx * mx + mi * mi < k) cout << "NO\n";
        else
        {
            cout << "YES\n";
            if (k == 0) goto e;
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {
                    if (!(i%2))
                    {
                        if (j % 2 == 0)
                        {
                            cout << "L";
                            --k;
                            if (!k)
                            {
                                ++i;
                                for (int k = j + 1; k < n; ++k)
                                    cout << "S";
                                cout << '\n';
                                goto e;
                            }
                        }
                        else cout << "S";
                    }
                    else
                    {
                        if (j % 2 == 0)
                            cout << "S";
                        else
                        {
                            cout << "L";
                            --k;
                            if (!k)
                            {
                                ++i;
                                for (int k = j + 1; k < n; ++k)
                                    cout << "S";
                                cout << '\n';
                                goto e;
                            }
                        }
                    }
                }
                cout << '\n';
            }
            e:
                for (int k = i; k < n; ++k, cout << '\n')
                    for (int l = 0 ; l < n; ++l)
                    {
                        cout << "S";
                    }
        }
    }
    return 0;
}

