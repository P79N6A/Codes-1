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
#define lowbit(x) (x & (-x))
#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1  1
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 100;

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k) {
        priority_queue<int, vector<int> > pq;
        int cnt = 0, x, tol = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x > 1) pq.push(x);
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (k) --k;
            else {
                if (pq.empty()) {
                    ans = -1;
                    break;
                }
                k += pq.top() - 2;
                pq.pop();
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
