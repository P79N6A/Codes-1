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
    string wo = "��";
    string zi = "��";
    while (cin >> k)
    {
        int cnt = k - 3;
        if (k % 2)
        {
            cout << "����Ի:\"";
            if (k == 1) cout << "�ӷ���,��֪��֮��?\n";
            else
            {
                cout << "�ӷ���,��֪�Ҳ�֪��";
                bool flag = 1;
                int cnnt = 0;
                for (int i = cnt - 1; cnt >= 0; --i)
                {
                    cout << "��֪";
                    if (flag) cout << wo;
                    else cout << zi;
                    flag = flag - 1;

                }
                cout << "֮��֪��֮��?\n";
            }
        }
        else
        {
            cout << "ׯ��Ի:\"";
            if (k == 2) cout << "�ӷ���,��֪�Ҳ�֪��֮��?\n";
            else
            {
                cout << "�ӷ���,��֪�Ҳ�֪��";
                bool flag = 1;
                int cnnt = 0;
                for (int i = cnt - 1; i >= 0; --i)
                {
                    cout << "��֪";
                    if (flag) cout << wo;
                    else cout << zi;
                    flag = flag - 1;
                }
                cout << "֮��֪��֮��?\n";
            }
        }
    }
    return 0;
}
