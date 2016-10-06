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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 111, MOD = 10001;
int x[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i < 2 * n; i += 2)
            scanf("%d", x + i);
        for (int a = 0; a <= 10000; ++a)
        {
            for (int b = 0; b <= 10000; ++b)
            {
                x[2] = (a * x[1] + b) % MOD;
                int temp = (a * x[2] + b) % MOD;
                if (temp != x[3]) continue;

                bool flag = 1;
                for (int i = 4; i <= 2 * n; ++i)
                {
                    int temp = (a * x[i - 1] + b) % MOD;
                    if (i % 2 == 0) x[i] = temp;
                    else
                    {
                        if (x[i] != temp)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag) goto label;
            }
        }
        label:
        for (int i = 2; i <= 2 * n; i += 2)
            cout << x[i] << '\n';
    }
    return 0;
}

