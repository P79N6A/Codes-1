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
const int MAXN = 3;

int ains[MAXN], nias[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        for (int i = 0; i < 3; ++i) scanf("%d", &ains[i]);
        for (int i = 0; i < 3; ++i) scanf("%d", &nias[i]);
        sort(ains, ains + 3); sort(nias, nias + 3);

        double ans = 0;
        if (nias[0] == nias[1] == nias[2])
        {
            if (ains[0] == ains[1] == ains[2])
            {
                if (ains[0] > nias[0]) ans = 1;
            }
            else if (ains[0] == ains[1])
            {
                if (ains[1] > nias[1]) ans = 1.0 / 6.0;
            }
            else if (ains[1] == ains[2])
            {
                if (ains[1] > nias[1]) ans = 1.0 / 6.0;
            }
        }
        else if (nias[0] == nias[1])
        {
            if (ains[0] == ains[1])
            {
                if (ains[1] > nias[1]) ans = 1;
                else ans = 1.0 / 6.0;
            }
            else if (ains[1] == ains[2])
            {
                if (ains[1] > nias[1]) ans = 1;
                else ans = 1.0 / 6.0;
            }
            else
            {
                if (ains[2] == nias[0])
                {
                    if (ains[1] > nias[0] || ains[0] > nias[0])
                        ans = 1/6.0;
                }
                else if (ains[2] > nias[0])
                {
                    ans = 1/6.0;
                }
            }
        }
        else if (nias[1] == nias[2])
        {
            if (ains[0] == ains[1])
            {
                if (ains[1] > nias[1]) ans = 1;
                else ans = 1.0 / 6.0;
            }
            else if (ains[1] == ains[2])
            {
                if (ains[1] > nias[1]) ans = 1;
                else ans = 1.0 / 6.0;
            }
            else
            {
                if (ains[2] == nias[1])
                {
                    if (ains[1] > nias[1] || ains[0] > nias[1])
                        ans = 1/6.0;
                }
                else if (ains[2] > nias[1])
                {
                    ans = 1/6.0;
                }
            }
        }
        else
        {
            if (ains[0] == ains[1] || ains[1] == ains[2]) ans = 1;
            else
            {

            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
