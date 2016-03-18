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
const int INF = 0x7f7f7f7f, MAXN = 1e5 + 111, MOD = 100000007;
int c[MAXN], x, n;

int lowbit(int x)
{
    return x &(-x);
}

void update(int i)
{
    while (i <= n)
    {
        c[i] += 1;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll t, lsmall, rbig;
    scanf("%I64d", &t);
    for (int kase = 1; kase <= t; ++kase)
    {
        scanf("%d", &n);
        ll ans = 0;
        memset(c, 0, sizeof c);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            update(x);
            lsmall = sum(x - 1); //���С�ڵ���
            rbig = n - x - (i - 1 - lsmall); //�ұߴ��ڵ���
            ans -= lsmall * rbig; //��˵Ľ�����ǲ���������
            if (rbig >= 2)
                ans += rbig * (rbig - 1) / 2; //�������
            //���������ȥ��������� = ��
        }
        printf("Case #%d: %I64d\n", kase, ans % MOD);
    }
    return 0;
}

