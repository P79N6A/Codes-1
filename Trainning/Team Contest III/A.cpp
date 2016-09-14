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
const int MAXN = 1e6 + 111;
double h, w, ans;
int main()
{
    //#ifdef GooZy
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    //#endif
    ans = 0;
    cin>>h>>w;
    ans = max(ans, min(h,w)/2);
    ans = max(ans, min(h,w/3));
    ans = max(ans, min(h/3,w));
    printf("%.3f\n",ans);
    return 0;
}
