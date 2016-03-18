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

const int MAXN = 1e2 + 11;

struct Student
{
	string sid, cid;
	string name;
	int score[4];
}student[MAXN];

map<string, bool> is;

int main()
{
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	bool flag = 1;
	while (flag)
	{
		cout << "Welcome to Student Performance Management System (SPMS).\n\n";
		cout << "1 - Add\n";
		cout << "2 - Remove\n";
		cout << "3 - Query\n";
		cout << "4 - Show ranking\n";
		cout << "5 - Show Statistics\n";
		cout << "0 - Exit\n\n";
		int op; cin >> op;
		switch(op)
		{
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: cout << "Showing the ranklist hurts students' self-esteem. Don't do that.\n"; break;
			case 5: break;
			case 0: flag = 0; break;
		}
	}
	return 0;
}

