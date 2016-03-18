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

const int MAXN = 1e6 + 111;

char keyboard[4][20] = {
	{'`','1','2','3','4','5','6','7','8','9','0','-','='},
	{'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'},
	{'A','S','D','F','G','H','J','K','L',';','\''},
	{'Z','X','C','V','B','N','M',',','.','/'},
};

int len[4] = {13, 13, 11, 10};

int main()
{
	char c;
	while (~scanf("%c", &c))
	{
		bool flag = 1;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < len[i]; ++j)
			{
				if (keyboard[i][j] == c)
				{
					printf("%c",keyboard[i][j - 1]);
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			printf("%c", c);
	}
	return 0;
}

