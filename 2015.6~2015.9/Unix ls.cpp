#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;

const int MAXN = 1e6 + 111;

string name[110];

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int n;
	while (cin >> n)
	{
		int mx = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> name[i];
			if (name[i].length() > mx) //记录最大名字长度 
				mx = name[i].length();
		}
		//cout << mx << endl;
		sort(name, name + n);
		mx += 2;
		int r = 62 / mx; //每行放几个
		//cout << r << endl; 
		int len = n / r + (n % r != 0); //放几行
		//cout << len << '\n'; 
		cout << "------------------------------------------------------------\n";
		for (int j = 0; j < len; ++j)
		{
			for (int i = j; i < n; i += len)
			{
				cout.width(mx); //设置输出宽度 
				cout << setiosflags(ios::left) << name[i]; //左对齐 
			}
			cout << '\n';
		}
	}
	return 0;
}

