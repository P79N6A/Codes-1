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

ll ji, ou;
int ans[MAXN];

int main()
{
    #ifdef LOCAL
    //freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, q, op, x;
    scanf("%d%d", &n, &q);
    ji = ou = 0;
    ll lastji = 0;
    bool odd = 1;
    for (int i = 0; i < q; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            ji += x;
            ou += x;
        }
        else {
            if (labs(ji - lastji) % 2 && odd) --ji, ++ou, lastji = ji;
            else if(labs(ji - lastji) % 2 && !odd) ++ji, --ou, lastji = ji;
            else if (labs(ji - lastji) % 2 == 0) {
                if (odd) ++ji, --ou, lastji = ji, odd = 0;
                else --ji, ++ou, lastji = ji, odd = 1;
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        int indx = ((i + ji) % n + n) % n;
        int indx2 = ((i + ou) % n + n) % n;
        if (i % 2 == 0)
            ans[indx] = i + 1;
        else ans[indx2] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", ans[i]);
        if (i != n - 1) putchar(' ');
        else putchar('\n');
    }
    return 0;
}
