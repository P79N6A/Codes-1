#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e3 + 111;
int num[MAXN];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n) && n)
	{
		while(1)
		{
			stack<int> s;
			s.push(0);
			scanf("%d", num);
			if (num[0] == 0)
				break;
			for (int i = 1; i < n; ++i)
				scanf("%d", num + i);
			bool flag = 1;
			int mi = 1;
			for (int i = 0; i < n; ++i)
			{
				//cout << num[i] << ':'<< s.top() << endl;
				if (num[i] > s.top())
				{
					bool flag2 = 0;
					for (int j = mi; j <= num[i]; ++j)
					{
						flag2 = 1;
						s.push(j);
					}
					if (flag2)
					{
						mi = num[i] + 1;
						s.pop();
					}
					else
					{
						flag = 0;
						break;
					}
				}
				else if (num[i] == s.top())
				{
					s.pop();
				}
				else
				{
					flag = 0;
					break;
				}
			}
			cout << (flag ? "Yes\n" : "No\n");
		}
		cout << '\n';
	}
	return 0;
}

