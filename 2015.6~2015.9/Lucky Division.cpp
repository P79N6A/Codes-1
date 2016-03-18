#include<iostream>
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
const int MAXN = 1e6 + 111;

int main()
{
#ifdef LOCAL
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	int n; cin >> n;
	int num[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 747, 777, 774, 477};
	bool flag = 0;
	for (int i = 0; i < 14; ++i)
	{
		if (n % num[i] == 0)
		{
			cout << "YES\n";
			flag = 1;
			break; 
		}
	}
	if (!flag)
		cout << "NO\n";
	return 0;
}

