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
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

bool show[30][30];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    string s;
    while (cin >> s && s[0] != '*') {
        bool flag = 1;
        int up = s.length() - 1;
        for (int i = 1; i < up && flag; ++i) {
            memset(show, 0, sizeof show);
            for (int j = 0; j < s.length() - i; ++j) {
                if (show[s[j] - 'A'][s[j + i] - 'A']) {
                    flag = 0;
                    break;
                }
                show[s[j] - 'A'][s[j + i] - 'A'] = 1;
            }
        }
        cout << s << ' ';
        if (flag) cout << "is surprising.\n";
        else cout << "is NOT surprising.\n";
    }
    return 0;
}
