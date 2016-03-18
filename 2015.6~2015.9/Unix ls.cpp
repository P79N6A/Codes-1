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
			if (name[i].length() > mx) //��¼������ֳ��� 
				mx = name[i].length();
		}
		//cout << mx << endl;
		sort(name, name + n);
		mx += 2;
		int r = 62 / mx; //ÿ�зż���
		//cout << r << endl; 
		int len = n / r + (n % r != 0); //�ż���
		//cout << len << '\n'; 
		cout << "------------------------------------------------------------\n";
		for (int j = 0; j < len; ++j)
		{
			for (int i = j; i < n; i += len)
			{
				cout.width(mx); //���������� 
				cout << setiosflags(ios::left) << name[i]; //����� 
			}
			cout << '\n';
		}
	}
	return 0;
}

