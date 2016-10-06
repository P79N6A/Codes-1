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
const int MAXN = 1e6 + 1;

int prime[MAXN], cnt;
double dp[MAXN];
bool is[MAXN];

void sieve()
{
    cnt = 0;
    memset(is, 0, sizeof is);
    for (int i = 2; i < MAXN; ++i)
    {
        if (is[i]) continue;
        prime[cnt++] = i;
        for (int j = i * 2; j < MAXN; j += i)
        {
            is[j] = 1;
        }
    }
}

void init()
{
    sieve();
    dp[1] = 0;
    for (int i = 2; i < MAXN; ++i)
    {
        double sum = 0, p = 0, temp = 0;
        for (int j = 0; j < cnt && prime[j] <= i; ++j)
        {
            ++sum;
            if (i % prime[j] == 0)
            {
                ++p;
                temp += dp[i / prime[j]];
            }
        }
        temp /= sum;
        dp[i] = (1 + dp[i]) * (1 - p / sum) + temp;
    }
}

int main()
{
    init();
    int t, n;
    for (int kase = scanf("%d", &t); kase <= t; ++kase)
    {
        scanf("%d", &n);
        printf("Case %d: %.10f\n", kase, dp[n]);
    }
    return 0;
}
