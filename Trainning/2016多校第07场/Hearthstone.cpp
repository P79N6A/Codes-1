/*
  ���⣺A�����������ٳ����ţ�B�������ö�����ʧX���ʣ���Ӯ���ֵĸ����Ƕ��٣�
 */
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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << " @ ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 22;

// ȡ��i��A�࣬j��B��ķ�����
ll dp[MAXN][MAXN];
ll fac[MAXN], c[MAXN][MAXN];
int val[MAXN];

inline void init() {
    fac[0] = 1;
    for (int i = 1; i <= 20; ++i) fac[i] = i * fac[i - 1];
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j || j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    dp[0][1] = dp[1][0] = 1;
    for (int i = 1; i <= 20; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            if (j < i) dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i][j - 1];
        }
    }
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, p, n, m; scanf("%d", &t);
    init();
    while (t --) {
        scanf("%d%d%d", &p, &n, &m);
        for (int i = 0; i < m; ++i) scanf("%d", &val[i]);
        ll up = 0, down = fac[m + n];
        // ö��B���ȡ�����ʣ�µ�A��ֱ����ϼ���
        for (int i = 0; i < (1 << m); ++i) {
            int sum = 0, cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) sum += val[j], ++cnt;
            }
            if (sum >= p) {
                up += dp[cnt - 1][cnt] * c[n][cnt - 1]
                        * fac[cnt - 1] * fac[cnt] * fac[n + m - 2 * cnt + 1];
                // �ر���ȫ����ȡ���������Ϊƽ�������i == j - 1ʱ�ǽ���̬
                if (cnt == m && n != m - 1)
                    up += dp[n][m] * fac[n] * fac[m];
            }
        }
        ll gcd = __gcd(up, down);
        printf("%lld/%lld\n", up / gcd, down / gcd);
    }
    return 0;
}
