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
const int MAXN = 1e3 + 111;
string name[MAXN];

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while( cin >> n && n )
	{
	    for( int i = 0; i < n; ++i )
	       cin >> name[i];
	    sort(name, name + n);
	    int mid = n / 2 - 1;
	    int mi = min(name[mid].length(), name[mid + 1].length());
	    string ans;
	    for( int i = 0; i < mi ; ++i )
	    {
	        if( i == name[mid].length() - 1)
	        {
	            ans += name[mid][i];
	            break;
            }
	        if(name[mid][i] != name[mid + 1][i])
	        {
	            char t = name[mid][i] + 1;
	            if( (ans + t >= name[mid] && ans + t < name[mid + 1]  ))
	            {
	                ans += t;
	                break;
                }
                else
                {
                    ans += name[mid][i];
                    if(ans < name[mid + 1] && ans >= name[mid])
                        break;
                    for(int j = i + 1; j < name[mid].length(); ++j)
                    {
                        if(j == name[mid].length() - 1)
                        {
                            ans += name[mid][j];
                            break;
                        } 
                        if(name[mid][j] < 'Z')
                        {
                            ans += name[mid][j] + 1;
                            break;
                        }
                        else ans += name[mid][j];
                    }
                    break;
                }
            }
            else ans += name[mid][i];
        }
        cout << ans << '\n';
    }
	return 0;
}

