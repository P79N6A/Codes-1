#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e6 + 111;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n; scanf("%d", &n);
	getchar();
	while (n --)
	{
		char s[200];
		stack<char> sta;
		gets(s);
		bool flag = 1;
		for (int i = 0; s[i]; ++i)
		{
			if (s[i] == '(' || s[i] == '[')
			{
				sta.push(s[i]);
			}
			else
			{
				if (sta.empty()) {flag = 0; break;}
				char c = sta.top(); sta.pop();
				if (s[i] == ')' && c == '(') continue;
				else if (s[i] == ']' && c == '[') continue;
				else { flag = 0; break;}
			}
		}
		if (!sta.empty())
			flag = 0;
		printf("%s\n", (flag? "Yes": "No"));
	}
	return 0;
}

