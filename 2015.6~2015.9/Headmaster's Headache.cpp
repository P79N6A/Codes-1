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
const int MAXN = 1e6 + 111;
const int INF = 0x3f3f3f3f;
int s, m, n, dp[150][1 << 8][1 << 8], st[150], c[150];

int DP(int i, int s0, int s1, int s2)
{
    if (i == m + n) return s2 == (1 << s) - 1 ? 0 : INF;
    int& ans = dp[i][s1][s2];
    if (ans >= 0) return ans;
    ans = INF;
    if (i >= m) ans = DP(i + 1, s0, s1, s2); //不选
    int m0 = st[i] & s0, m1 = st[i] & s1;   //m0:差两个人教的变成差一个人教的
    s0 ^= m0; s1 = (s1 ^ m1) | m0; s2 |= m1; //s0^= m0之后就是当前剩余的没人教的课程
    ans = min(ans, c[i] + DP(i + 1, s0, s1, s2)); //选
    return ans;
}

int main()
{
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
	while (cin >> s >> m >> n && (s || m || n))
	{
	    memset(dp, -1, sizeof dp);
	    int sub, low, status;
	    string S; cin.get();
	    for (int i = 0; i < n + m; ++i)
	    {
	        status = 0;
	        getline(cin, S);
	        stringstream ss(S);
	        ss >> c[i];
	        while (ss >> sub)
	        {
	            int low = sub - 1;
	            status |= 1 << low;
	        }
	        st[i] = status; //第i个老师能教的科目
	    }
	    cout << DP(0, (1 << s) - 1, 0, 0) << '\n';  //初始状态所有科目都没老师教归入集合s0
	}
	return 0;
}
