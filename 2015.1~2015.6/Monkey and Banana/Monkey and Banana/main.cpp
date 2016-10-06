#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10100;

struct Block{
    int s;
    int a, b, c;
    bool operator < (const Block& t)const{
        return s > t.s;
    }
}b[3 * MAXN];

int dp[3 * MAXN]; //放置第i个砖块可到达的最大高度

int main() {
    ios_base::sync_with_stdio(0);
    int n, cnt = 0;
    while (cin >> n && n)
    {
        Block tem;
        int l , w, h, k = 0;
        for (int i = 0; i < n; ++i) //不同角度放置都视为新的砖块
        {
            cin >> l >> w >> h;
            tem.a = l, tem.b = w, tem.c = h, tem.s = l * w;
            b[k++] = tem;
            tem.a = w, tem.b = h, tem.c = l, tem.s = w * h;
            b[k++] = tem;
            tem.a = h, tem.b = l, tem.c = w, tem.s = h * l;
            b[k++] = tem;
        }
        sort(b, b + 3 * n);  //从大到小排序
        dp[0] = b[0].c;
        int ans = 0;
        for (int i = 1; i < n * 3; ++i)  //dp[i] = max(dp[j]) + b[i].c;
        {
            dp[i] = b[i].c;
            for (int j = 0; j < i; ++j)
            {
                if ((b[i].a < b[j].a && b[i].b < b[j].b )|| (b[i].a < b[j].b && b[i].b < b[j].a))
                {
                    dp[i] = max(dp[i], dp[j] + b[i].c);
                    //cout << dp[i] << ' ';
                    ans = max(ans, dp[i]);
                }
            }
            //cout << endl;
        }
        cout << "Case " << ++cnt << ": maximum height = " << ans << '\n';
    }
    return 0;
}
