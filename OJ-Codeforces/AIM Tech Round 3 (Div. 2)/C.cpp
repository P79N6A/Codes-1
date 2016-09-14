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
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

char s[MAXN];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (~scanf("%s", s)) {
        int len = strlen(s);
        bool bg = 0, is = 1;
        for (int i = 0; i < len; ++i) {
            if (s[i] != 'a') {
                if (!bg) bg = 1;
                s[i] -= 1;
                is = 0;
            }
            else if (bg) break;
        }
        if (is) s[len - 1] = 'z';
        puts(s);
    }
    return 0;
}
