#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 131;
int s, m, n, teach[MAXN], cost[MAXN], dp[MAXN][1 << 8][1 << 8];

int DP(int i, int s1, int s2)
{
    if (i == m + n) return s2 == (1<<s) - 1 ? 0 : INF;  //每个科目都至少两个老师了，那么久不需要再花钱了
    int &ret = dp[i][s1][s2];
    if (ret >= 0) return ret;
    ret = INF;
    if (i >= m) ret = DP(i + 1, s1, s2);         //不选
    s2 |= (s1 & teach[i]);                       //老师能教，并且差一个老师，那么一并运算，剩下的就是满足条件的科目
    s1 |= teach[i];                              //或上去，没人教的科目肯定变成差一个人教
    ret = min(ret, cost[i] + DP(i + 1, s1, s2)); //选
    return ret;
}

int main()
{
    while (cin >> s >> m >> n && s)
    {
        cin.get();
        string ss;
        int x;
        for (int i = 0; i < m + n; ++i)
        {
            getline(cin, ss);
            stringstream sss(ss);
            sss >> cost[i];
            teach[i] = 0;
            while(sss >> x)
            {
                teach[i] |= 1 << (x - 1);
            }
        }
        memset(dp, -1, sizeof dp);
        //for (int i = 0; i < m + n; ++i) cout << cost[i] << ':' << teach[i] << endl;
        cout << DP(0, 0, 0) << '\n';
    }
    return 0;
}

