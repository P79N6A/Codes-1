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

long double ans[100];
char s[1000000];

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int kase = 1;
    long double mul = (long double)1000 / 1024;
    ans[0] = 1;
    for(int i = 1; i <= 10; i++) ans[i] = ans[i - 1] * 1000 / 1024;
    while(t--) {
        scanf("%s", s);
        int pos = 0;
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(s[i] == '[') {
                pos = i; break;
            }
        }
        pos++;
        long double rans;
        if(s[pos] == 'B') rans = ans[0];
        else if(s[pos] == 'K') rans = ans[1];
        else if(s[pos] == 'M') rans = ans[2];
        else if(s[pos] == 'G') rans = ans[3];
        else if(s[pos] == 'T') rans = ans[4];
        else if(s[pos] == 'P') rans = ans[5];
        else if(s[pos] == 'E') rans = ans[6];
        else if(s[pos] == 'Z') rans = ans[7];
        else if(s[pos] == 'Y') rans = ans[8];
        rans = 1 - rans;
        rans = rans * 100;
        printf("Case #%d: %.2lf%%\n", kase++, rans);
    }
    return 0;
}
