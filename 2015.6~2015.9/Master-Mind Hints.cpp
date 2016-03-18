#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int MAXN = 1e3 + 11;
int num[MAXN];
int guess[MAXN];

int hnum[10];
int htem[10];
int hguess[10];

int main()
{
	int n;
	int cnt = 0;
	while (scanf("%d", &n) && n)
	{
		printf("Game %d:\n", ++cnt);
		memset(htem, 0, sizeof htem);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", num + i);
			++htem[num[i]];
		}
		while(1)
		{
			for (int i = 1; i <= 9; ++i)
				hnum[i] = htem[i];
			memset(hguess, 0, sizeof hguess);
			for (int i = 0; i < n; ++i)
			{
				scanf("%d", guess + i);
				++hguess[guess[i]];
			}
			if (guess[0] == 0)
				break;
			int strong = 0;
			for (int i = 0; i < n; ++i)
			{
				if (num[i] == guess[i])
				{
					++strong;
					--hnum[num[i]];
					--hguess[num[i]];
				}
			}
			int weak = 0;
			for (int i = 1; i <= 9; ++i)
			{
				weak += min(hnum[i], hguess[i]);
			}
			printf("    (%d,%d)\n", strong, weak);
		}
	}
	return 0;
}

