#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, dp[25][25][25][25];
bool has[25][25]; //��¼����Ƿ���ӣ��

int sum(int u, int d, int l, int r) //ͳ�������ӣ����
{
    int ret = 0;
    for (int i = u + 1; i <= d; ++i)
        for (int j = l + 1; j <= r; ++j)
        {
            if (has[i][j]) ++ret;
            if (ret == 2) return 2; //��������Ҳ���Ƕ�����������ͳһ�ݹ鴦��ֱ����Ϊͬһ���
        }
    return ret;
}

int dfs(int u, int d, int l, int r)
{
    int &ret = dp[u][d][l][r];
    if (ret != -1) return ret;
    int total = sum(u,d,l,r);
    if (total == 1) return ret = 0; //һ��ӣ�ҷ���0�������и���
    if (!total) return ret = INF;  //û��ӣ�ң���Ч�и�
    ret = INF;
    for (int i = u + 1; i < d; ++i) //ˮƽ�и�
        ret = min(ret, dfs(u,i,l,r) + dfs(i,d,l,r) + r - l);
    for (int i = l + 1; i < r; ++i) //��ֱ�и�
        ret = min(ret, dfs(u,d,l,i) + dfs(u,d,i,r) + d - u);
    return ret;
}

int main()
{
	int k, x, y, kase = 0;
    while(cin >> n >> m >> k)
    {
	   memset(dp, -1, sizeof dp);
	   memset(has, 0, sizeof has);
	   for (int i = 0; i < k; ++i) cin >> x >> y, has[x][y] = 1;
	   cout << "Case " << ++kase << ": " << dfs(0, n, 0, m) << '\n';
    }
	return 0;
}

