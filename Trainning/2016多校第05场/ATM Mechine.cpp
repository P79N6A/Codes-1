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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 2111;

// dp[i][j]: �Ʋ���0~i�ڣ�ʣ��j�ξ��������ȡ�����вƲ�����������
double dp[MAXN][13];
int m, n;

double dfs(int x, int y) {
    double &ret = dp[x][y];
    if (ret != -1) return ret;
    if (!x) return ret = 0;
    if (!y) return ret = INF;
    ret = INF;
    double base = x + 1;
    for (int i = 0; i <= x; ++i) {
        // ʧ�ܣ�ȡ��i֮��ʧ�ܣ�˵���Ʋ���0 ~ i-1֮��
        // �ɹ���ȡ��i֮��ɹ���˵���Ʋ���0 ~ x-i֮��
        // �󷽳˵ĸ����ǲƲ���ȡֵ����
        ret = min(ret, dfs(x - i, y) * (x - i + 1) / base + dfs(i - 1, y - 1) * i / base + 1);
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 13; ++j)
                dp[i][j] = -1;
    }
    while (~scanf("%d%d", &n, &m)) {
        m = min(m, 11);
        printf("%.6f\n", dfs(n, m));
    }
    return 0;
}
