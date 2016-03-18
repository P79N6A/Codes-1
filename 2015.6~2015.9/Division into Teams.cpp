#include<iostream>
#include<cctype>
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
const int MAXN = 1e5 + 111;
struct A{
	int num, id;
	bool operator <(const A& t)const
	{
		return num < t.num;
	}
}a[MAXN];
vector<A> team1, team2;

int main()
{
    int n, mx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
	{
		cin >> a[i].num;
		a[i].id = i + 1;
		mx = max(mx, a[i].num);
	}
	sort(a, a + n);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i += 2)
	{
		team1.push_back(a[i]);
		sum1 += a[i].num;
		if (i + 1 == n) break;
		team2.push_back(a[i + 1]);
		sum2 += a[i + 1].num;
	}
	int len = 0;
	while (abs(sum1 - sum2) > mx)
	{
		sum1 += team2[len].num - team1[len].num;
		sum2 += team1[len].num - team2[len].num;
		swap(team1[len], team2[len]);
		++len;
	}
	cout << team1.size() << '\n' << team1[0].id;
	for (int i = 1; i < team1.size(); ++i)
		cout << ' ' << team1[i].id;
	cout << '\n';
	cout << team2.size() << '\n' << team2[0].id;
	for (int i = 1; i < team2.size(); ++i)
		cout << ' ' << team2[i].id;
	cout << '\n';
	return 0;
}

