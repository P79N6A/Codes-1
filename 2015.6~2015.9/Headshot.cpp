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
const int INF = 0x7f7f7f7f, MAXN = 1e6 + 111;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    string s;
    while (cin >> s)
    {
        int n = s.size(), a = 0, b = 0;
        s += s[0];
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i + 1] == '0')
                    ++a;
                ++b;
            }
        }
        if (a * n > b * b) cout << "SHOOT\n";
        else if (a*n == b*b) cout << "EQUAL\n";
        else cout << "ROTATE\n";
    }
    return 0;
}

