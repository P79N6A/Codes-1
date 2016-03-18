#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100;

struct Block{
    int s;
    int a, b, c;
    Block(int a, int b, int c, int s):a(a),b(b),c(c),s(s){}
    Block(){}
    bool operator < (const Block& t)const{
        return s > t.s;
    }
}b[MAXN];

int dp[MAXN];

int main() {
    #ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
	#endif
    int n, kase = 0;
    while (cin >> n && n)
    {
        int l, w, h, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> l >> w >> h;
            b[cnt++] = Block(l, w, h, l * w);
            b[cnt++] = Block(w, h, l, w * h);
            b[cnt++] = Block(h, l, w, h * l);
        }
        sort(b, b + 3 * n);
        dp[0] = b[0].c;
        int ans = 0;
        for (int i = 1; i < n * 3; ++i)
        {
            dp[i] = b[i].c;
            for (int j = 0; j < i; ++j)
            {
                if ((b[i].a < b[j].a && b[i].b < b[j].b )|| (b[i].a < b[j].b && b[i].b < b[j].a))
                {
                    dp[i] = max(dp[i], dp[j] + b[i].c);
                    ans = max(ans, dp[i]);
                }
            }
        }
        cout << "Case " << ++kase << ": maximum height = " << ans << '\n';
    }
    return 0;
}
