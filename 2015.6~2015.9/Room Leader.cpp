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
const int MAXN = 111;

struct P
{
    string name;
    int sum;
    bool operator < (const P& t)const
    {
        return sum < t.sum;
    }
}p[MAXN];

int main()
{
 	int n; cin >> n;
 	int pl, m, a, b, c, d, e;
 	for(int i = 0; i < n; ++i)
 	{
 	    cin >> p[i].name >> pl >> m >> a >> b >> c >> d >> e;
 	    p[i].sum = 100 * pl - 50 * m + a + b + c + d + e;
    }
    sort(p, p + n);
    cout << p[n - 1].name << '\n';
	return 0;
}

