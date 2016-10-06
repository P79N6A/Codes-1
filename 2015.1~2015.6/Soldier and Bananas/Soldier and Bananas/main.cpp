#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 5000005;
typedef long long ll;
ll dp[MAXN];
bool is[MAXN]; //第i个数是否为素数
int prime[MAXN], p;

void seive() { //素数筛法
    memset(is, true, sizeof is);
    for(int i = 2; i <= MAXN; ++i) {
        if(is[i]) {
            prime[p++] = i; //把素数存下来
            for(int j = i + i; j <= MAXN; j += i) is[j] = false;
        }
    }
}

int main() {
    seive();
    for (int i = 2; i < MAXN; ++i)
    {
        if (is[i]) //如果第i个是素数
        {
            dp[i] = 1;
            continue;
        }
        for (int j = 0; j < p; ++j) //找到第一个是它整除的数
        {
            if (i % prime[j] == 0)
            {
                dp[i] = dp[i / prime[j]] + 1;
                break;
            }
        }
    }
    for (int i = 3; i < MAXN; ++i) //处理为前i个和
        dp[i] += dp[i - 1];
    int t;
    scanf("%d",&t);
    while (t --)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%I64d\n", dp[a] - dp[b]);
    }
    return 0;
}
