#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;

bool is(string s)
{
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '#') return 1;
        else if (!isspace(s[i])) return 0;
    }
    return 0;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	string s;
	bool line = 0;
	while(getline(cin, s))
	{
	    if(is(s))
	    {
	        if(line) 
            {
                cout << '\n';
                line = 0;
            }
	        cout << s << '\n';
        }
        else
        {
            line = 1;
            for(int i = 0; i < s.length(); ++i)
            {
                if(!isspace(s[i])) 
                    cout << s[i];
            }
        }
    }
    if(line) cout << '\n';
	return 0;
}

