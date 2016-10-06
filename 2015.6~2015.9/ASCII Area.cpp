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
using namespace std;
#define pr(x) cout << "#x = " << (x) << '\n';
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 111;
string s[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int h, w;
    while (cin >> h >> w)
    {
        int a = 0, b = 0;
        for (int i = 0; i < h; ++i)
            cin >> s[i];
        int cnta = 0, cntb = 0;
        for (int i = 0; i < h; ++i)
        {
            cnta = 0, cntb = 0;
            for (int j = 0; j < w; ++j)
            {
                if (s[i][j] == '\\' || s[i][j] == '/')
                    ++cnta;
                else
                {
                    if (cnta % 2)
                        ++cntb;
                }
            }
            a += cnta, b += cntb;
        }
        cout << a / 2 + b << '\n';
    }
    return 0;
}

