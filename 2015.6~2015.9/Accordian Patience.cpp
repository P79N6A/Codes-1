#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
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
    while (cin >> s && s != "#")
    {
        vector<string> v[60];
        v[0].push_back(s);
        for (int i = 1; i < 52; ++i)
        {
            cin >> s;
            v[i].push_back(s);
        }
        for (int i = 0; i < 52; ++i)
        {
            for (int j = 0; j < i; ++j)
        }
    }
    return 0;
}

