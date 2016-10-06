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
struct A{
    int x, y;
}a[25];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int n;
	while (cin >> n)
	{
	    for (int i = 0; i < n; ++i)
            cin >> a[i].x >> a[i].y;
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; j < n; ++j)
                    for (int l = k + 1; k < n; ++k)
                    {
                        
                    }
        
    }
	return 0;
}

