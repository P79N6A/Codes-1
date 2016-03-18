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
struct N
{
    int id;
    int num;
    bool exist;
    bool operator <(const N& t)const
    {
        return num < t.num;
    }
}num[26];

bool cmp(N t, N m)
{
    return t.id < m.id;
}

int main()
{
 	string s;
 	int k;
 	cin >> s >> k;
 	for(int i = 0; i < s.length(); ++i)
 	{
 	    ++num[s[i] - 'a'].num;
 	    num[s[i] - 'a'].exist = 1;
    }
    for(int i = 0; i < 26; ++i) num[i].id = i;
    sort(num, num + 26);
    int sum = 0;
    for(int i = 0; i < 26; ++i)
    {
        sum += num[i].num;
        if(sum > k) break;
        num[i].exist = 0;
    }
    sort(num, num + 26, cmp);
    int ans = 0;
    for(int i = 0; i < 26; ++i) if(num[i].exist) ++ans;
    cout << ans << '\n';
    for(int i = 0; i < s.length(); ++i)
    {
        if(num[s[i] - 'a'].exist)
            cout << s[i];
    }
    cout << '\n';
	return 0;
}

