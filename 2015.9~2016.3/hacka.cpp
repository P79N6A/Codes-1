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
string s[MAXN];

int main()
{
    int k;
    string wo = "我";
    string zi = "子";
    while (cin >> k)
    {
        int cnt = k - 3;
        if (k % 2)
        {
            cout << "惠子曰:\"";
            if (k == 1) cout << "子非鱼,安知鱼之乐?\n";
            else
            {
                cout << "子非我,安知我不知子";
                bool flag = 1;
                int cnnt = 0;
                for (int i = cnt - 1; cnt >= 0; --i)
                {
                    cout << "不知";
                    if (flag) cout << wo;
                    else cout << zi;
                    flag = flag - 1;

                }
                cout << "之不知鱼之乐?\n";
            }
        }
        else
        {
            cout << "庄子曰:\"";
            if (k == 2) cout << "子非我,安知我不知鱼之乐?\n";
            else
            {
                cout << "子非我,安知我不知子";
                bool flag = 1;
                int cnnt = 0;
                for (int i = cnt - 1; i >= 0; --i)
                {
                    cout << "不知";
                    if (flag) cout << wo;
                    else cout << zi;
                    flag = flag - 1;
                }
                cout << "之不知鱼之乐?\n";
            }
        }
    }
    return 0;
}
