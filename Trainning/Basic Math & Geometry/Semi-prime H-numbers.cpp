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
const int MAXN = 1000001;

vector<ll> p;
int ans[MAXN], len = 0;

void init() {
    for (int i = 5; i <= MAXN; i += 4) {
        bool flag = 1;
        for (int j = 5; j * j <= i; j += 4) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            p.push_back(i);
        }
    }
    for (int i = 0; i < p.size(); ++i) {
        for (int j = i; j < p.size(); ++j) {
            if (p[i] * p[j] > MAXN) {
                break;
            }
            if ((p[i] * p[j] - 1) % 4 == 0)
                ans[len++] = p[i] * p[j];
        }
    }
    sort(ans, ans + len);
    len = unique(ans, ans + len) - ans;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int h;
    init();
    while (~scanf("%d", &h) && h) {
        int ret = upper_bound(ans, ans + len, h) - ans;
        printf("%d %d\n", h, ret);
        //for (int i = 0; i < ret; ++i) printf("%d ", ans[i]); putchar('\n');
    }
    return 0;
}
