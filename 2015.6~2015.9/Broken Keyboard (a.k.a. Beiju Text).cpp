#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 1e5 + 111;
char s[MAXN];
int go[MAXN], last, cur;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while (~scanf("%s" , s + 1))
	{
		int len = strlen(s + 1);
		last = cur = 0;
		go[0] = 0;
		for (int i = 1; i <= len; ++i)
		{
			if (s[i] == '[') cur = 0;
			else if (s[i] == ']') cur = last;
			else
			{
				go[i] = go[cur]; //i字符指向光标所在字符的下个字符 
				go[cur] = i;     //光标所在字符指向i字符 
				if (last == cur) last = i;
				cur = i;
			}
		}
		for (int i = go[0]; i != 0; i = go[i])
			cout << s[i];
		cout << '\n';
	}
	return 0;
}

