#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

int len;
bool have[20][20];
ll dp[20][20];

bool judge(int x, int y)
{
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx >= 1 && nx <= len && ny >= 1 && ny <= len && have[nx][ny])
                return 1;
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    char s[20];
    while (~scanf("%s", s + 1))
    {
        len = strlen(s) - 1;
        memset(have, 0, sizeof have);
        for (int i = 1; i <= len; ++i)
        {
            if (isdigit(s[i]))
                have[s[i] - '0'][i] = 1;
            else if (s[i] != '?')
                have[s[i] - 'A' + 10][i] = 1;
        }
        bool flag = 0;
        for (int i = 1; i <= len; ++i)
        {
            for (int j = 1; j <= len; ++j)
            {
                if (have[i][j] && judge(i, j))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) printf("0\n");
        else
        {
            memset(dp, 0, sizeof dp);
        }
    }
    return 0;
}
