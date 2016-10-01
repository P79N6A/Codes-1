#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

string zone, s;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    while (cin >> zone >> s) {
        if (s[3] > '5') s[3] = '0';
        if (zone == "12") {
            if (s[0] > '1') {
                if (s[1] != '0')
                    s[0] = '0';
                else s[0] = '1';
            }
            else if (s[0] == '1') {
                if (s[1] > '2')
                    s[1] = '1';
            }
            else if (s[1] == '0') s[1] = '1';
        }
        else {
            if (s[0] > '2') {
                s[0] = '1';
            }
            else if (s[0] == '2') {
                if ((s[1] > '3'))
                    s[1] = '0';
            }
        }
        cout << s << '\n';
    }
    return 0;
}
