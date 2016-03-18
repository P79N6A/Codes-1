#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<iomanip>
#include<queue>
#include<bitset>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;

//集合中存入的是状态的id，以id代替内容物 
typedef set<int> Set;
 
map<Set, int> idCache;
vector<Set> setCache;  //凭借id号来查找集合 

int id(Set x)
{
	if (idCache.count(x))
		return idCache[x];
	else
	{
		setCache.push_back(x);
		return idCache[x] = setCache.size() - 1; //让id为vector中的下标 
	}
}

int main()
{
	//freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	int t; cin >> t;
	while (t --)
	{
		stack<int> s;
		int n; cin >> n;
		string op;
		for (int i = 0; i < n; ++i)
		{
			cin >> op;
			if (op[0] == 'P') s.push(id(Set())); //存入空集 
			else if (op[0] == 'D') s.push(s.top());
			else
			{
				Set x1 = setCache[s.top()]; s.pop();
				Set x2 = setCache[s.top()]; s.pop();
				Set x;
				if (op[0] == 'U') set_union(ALL(x1),ALL(x2),INS(x));
				if (op[0] == 'I') set_intersection(ALL(x1),ALL(x2),INS(x));
				if (op[0] == 'A') x = x2, x.insert(id(x1));
				s.push(id(x));
			}
			cout << setCache[s.top()].size() << endl;
		}
		cout << "***\n";
	}
	return 0;
}

