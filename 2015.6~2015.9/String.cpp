#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1e5 + 111;
typedef long long LL;
string s;
int k;
struct Sub{
	string s;
	int pos;
	bool operator < (const Sub& t)const
	{
		return s > t.s;
	}
};

int main()
{
	cin >> s >> k;
	priority_queue<Sub> pq;
	int len;
	for( len = 0; s[len]; ++len){ pq.push( Sub{ string(1,s[len]), len } ); }
	if (k > LL(len) * LL(len + 1) / 2)
	{
		cout << "No such line.\n" ; return 0 ;
	}
	else
	{
		int cnt = 0;
		while( !pq.empty() )  
		{
			Sub temp = pq.top() ; pq.pop() ;
			if( ++cnt == k )
			{
				cout << temp.s << '\n' ; return 0 ;
			}
			if( temp.pos != len - 1 )
			{
				temp.s += s[++temp.pos];
				pq.push( temp ) ;
			}
		}
	}
	return 0;
}

