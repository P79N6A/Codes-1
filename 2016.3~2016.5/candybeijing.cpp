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

struct P {
    int val, p;
    bool operator < (const P&t)const {
        return val < t.val;
    }
}a[500];
int org[500];
int num[500];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n;
    while (~scanf("%d", &n)){
        int ans = n;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].val);
            org[i] = a[i].val;
            a[i].p = i;
            num[i] = 1;
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            int pos = a[i].p;
            if (pos < n - 1 && org[pos] < org[pos + 1]) {
                if (num[pos] >= num[pos + 1]) {
                    ans += num[pos] - num[pos + 1] + 1;
                    num[pos + 1] = num[pos] + 1;
                }
            }
            if (pos > 0 && org[pos] < org[pos - 1]) {
                if (num[pos] >= num[pos - 1]) {
                    ans += num[pos] - num[pos - 1] + 1;
                    num[pos - 1] = num[pos] + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
