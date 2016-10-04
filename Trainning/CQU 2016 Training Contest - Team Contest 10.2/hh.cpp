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
int n;
char s[10000];
char by[] = "BKMGTPEZY";
int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &n);
    int kase = 0;
    while(n--){
        scanf("%s", s);
        printf("Case #%d: ",++kase);
        int len = strlen(s);
        int pos = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == '[') {
                pos = i;
                break;
            }
        }

        int x = 0;
        for(int i = 0; i < 9; ++i){
            if(s[pos+1]==by[i]) {
                x = i;
            }
        }
        double ans = 1;
        for(int i = 0; i < x; ++i){
            ans = ans*1000/1024;
        }
        ans = 1-ans;
        ans = ans*100;
        printf("%.2f%%\n",ans);
    }
    return 0;
}
