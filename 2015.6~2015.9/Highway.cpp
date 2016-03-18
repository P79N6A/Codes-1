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
const double eps = 1e-7;
struct V{
    double x, y;
    bool operator < (const V& t)const
    {
        return (x == t.x ? y > t.y : x < t.x);
    }
}v[MAXN];

double dis(double b, double a, double x)
{
    return sqrt(a * a + (b - x) * (b - x));
}

int main()
{
 	#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int l, n;
	double d;
	while( cin >> l >> d >> n)
	{
	    for(int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y;
	    sort(v, v + n);
	    int ans = 1;
	    double p = v[0].x + sqrt(d * d - v[0].y * v[0].y);
	    for(int i = 1; i < n; ++i)
	    {
	        if(dis(v[i].x, v[i].y, p) - d > eps)
	        {
	            ++ans;
	            p = v[i].x + sqrt(d * d - v[i].y * v[i].y);
            }
        }
        cout << ans << '\n';
    }
	return 0;
}

