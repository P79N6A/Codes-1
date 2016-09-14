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
const int MAXN = 1e3 + 111;

char s[MAXN];

int main()
{
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    scanf("%s", s);
    int len = strlen(s);
    bool in = 0, first = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '-') {
            in = 1;
            first = 0;
            putchar('-');
            ++i;
            putchar(s[i]);
        }
        else if (!in) {
            putchar(s[i]);
        }
        else {
            if (isdigit(s[i])) {
                if (s[i] != '0') {
                    if (!first) putchar('+'), first = 1;
                    putchar(s[i]);
                }
                else {
                    if (!first) putchar('+');
                    putchar(s[i]);
                }
            }
            else {
                in = 0;
                first = 0;
                putchar(s[i]);
            }
        }
    }
    putchar('\n');
    return 0;
}
