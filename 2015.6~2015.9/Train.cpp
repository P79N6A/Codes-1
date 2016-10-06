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

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n, s, c, add; cin >> n >> s >> c;
	string a, b, op; cin >> a >> b;
	if( b == "head" ) add = -1, s = (s < c ? 1 : n );
	else add = 1, s = (s > c ? n : 1);
	cin >> op;
	bool flag = 1;
	for(int i = 0; i < op.length(); ++i)
	{
	    if(op[i] == '0')
	    {
	        if(1 > c + add || c + add > n)
	           add = -add;
	        c += add;
	        if(c == s)
	        {
	            flag = 0;
	            cout << "Controller " << i + 1 << '\n';
	            break;
            }
        }
        else
        {
            if(1 > c + add || c + add > n)
	           add = -add;
	        c += add;
	        if( add == -1 ) s = n;
	        else s = 1;
        }
    }
    if(flag) cout << "Stowaway\n";
	return 0;
}

