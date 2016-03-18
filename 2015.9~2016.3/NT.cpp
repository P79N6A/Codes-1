#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define root 1, n, 1
#define lson l, m, rt << 1
#define ll long long
#define pr(x) cout << #x << '=' << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

char s[1111];
int len, num[11];

bool judge()
{
    int cur[11];
    for (int i = 0; i < 1000; ++i)
    {
        if (i % 8) continue;
        memset(cur, 0, sizeof cur);
        int temp = i, bit = 0;
        while (temp)
        {
            ++cur[temp % 10];
            temp /= 10;
            ++bit;
        }
        cur[0] += 3 - bit;
        bool flag = 1;
        for (int j = 0; j <= 9; ++j)
        {
            if (num[j] < cur[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
    }
    return 0;
}

int main()
{
    while (~scanf("%s", s))
    {
        len = strlen(s);
        bool ok = 0;
        if (len <= 3)
        {
            sort(s, s + len);
            do
            {
                int x = atoi(s);
                if (x % 8 == 0)
                {
                    ok = 1; break;
                }
            }while(next_permutation(s, s + len));
        }
        else
        {
            memset(num, 0, sizeof num);
            for (int i = 0; i < len; ++i)
            {
                ++num[s[i] - '0'];
            }
            ok = judge();
        }
        puts(ok? "YES" : "NO");
    }
    return 0;
}
