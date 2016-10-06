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
#include<bitset>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1111;
//d[i][j]��ʾ1~max(i,j)ȫ���߹���������λ��Ϊi��j(i>j)������Ҫ�ߵľ���
double x[MAXN], y[MAXN], dist[MAXN][MAXN], d[MAXN][MAXN];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
			{
			    dist[i][j] = dist[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		for (int i = n - 1; i >= 1; --i)
			for (int j = 1; j < i; ++j)
			{
				if (i == n - 1) d[i][j] = dist[i][n] + dist[j][n];//���յ㻹��Ҫ�ľ���
				else
					d[i][j] = min(d[i + 1][j] + dist[i][i + 1],d[i+1][i] + dist[j][i +1]);
			}
		d[1][1] = dist[1][2] + d[2][1];
		printf("%.2lf\n", d[1][1]);
	}
	return 0;
}

