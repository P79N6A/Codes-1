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
const int MAXN = 1e5 + 111;
typedef long long ll;

struct A{
    int id, v, ans;
}a[MAXN];

bool cmp1(A t, A tt)
{
    return t.id < tt.id;
}

bool cmp2(A t, A tt)
{
    return t.v > tt.v;
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n; 
	while(cin >> n)
	{
	    ll sum = 0;
	    bool flag = 0;
	    for(int i = 0; i < n; ++i)
        {
             cin >> a[i].v, sum += a[i].v;
             a[i].id = i;
             a[i].ans = -1;
        }
	    if(sum % 2) cout << "No\n";
	    else
	    {
	        sort(a, a + n, cmp2);
	        ll subsum = 0, tar = sum / 2;
	        for(int i = 0; i < n; ++i)
	        {
	            subsum += a[i].v;
	            a[i].ans = 1;
	            if( subsum == tar )
                {
                    flag = 1;
                    break;
                }
                else if(subsum > tar)
                {
                    subsum -= a[i].v;
                    a[i].ans = -1;
                }
            }
            if(flag)
            {
                sort(a, a + n, cmp1);
                cout << "Yes\n" << a[0].ans;
                for(int i = 1; i < n; ++i) cout << ' ' << a[i].ans;
                cout << '\n';
            }
            else cout << "No\n";
        }
    }
	return 0;
}

