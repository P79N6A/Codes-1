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
typedef pair<int, int> p;
const int MAXN = 1e4 + 111;
int a[MAXN][15];
int n, m;

void init(map<string, int>& id)
{
	string s;
	int k = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= m ; j++ )
        {
            getline( cin , s , j == m ? '\n' : ',' ) ;
            if( !id.count(s) ) id[s] = k++ ;
            a[i][j] = id[s];
        }
    }
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	while ( cin >> n >> m)
	{
		getchar();
		map<string, int> id;
		map<p, int> mp; 
		init(id);
		bool flag = 1;
		for (int j = 1; j < m; ++j)
			for (int k = j + 1; k <= m; ++k)
			{
				mp.clear();
				for (int i = 1; i <= n; ++i)
				{
					int id1 = a[i][j], id2 = a[i][k];
					p t = make_pair(id1, id2);
					if (mp.count(t))
					{
						flag = 0;
						cout << "NO\n";
						cout << mp[t] << ' ' << i << '\n';
						cout << j << ' ' << k << '\n';
						goto e;
					}
					else
					{
						mp[t] = i;
					}
				}
			}
		if (flag) cout << "YES\n";
		e: ;
	} 
	return 0;
}
