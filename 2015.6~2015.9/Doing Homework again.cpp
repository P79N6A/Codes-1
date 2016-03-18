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
const int MAXN = 1e3 + 111;
struct Object{
    int day, score;
    bool operator <(const Object& t)const
    {
        return (score == t.score? day < t.day : score > t.score);
    }
}obj[MAXN];
bool vis[10000];

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	int kase, n; cin >> kase;
	while(kase --)
    {
        cin >> n;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i) cin >> obj[i].day;
        for (int i = 0; i < n; ++i) cin >> obj[i].score;
        sort(obj, obj + n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int j;
            for (j = obj[i].day; j > 0; --j)
            {
                if (!vis[j])
                {
                    vis[j] = 1;
                    break;
                }
            }
            if (j == 0) ans += obj[i].score;
        }
        cout << ans << '\n';
    }
	return 0;
}


