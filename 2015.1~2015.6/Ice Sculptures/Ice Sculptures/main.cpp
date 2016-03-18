#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2e4 + 111;

int t[MAXN];

int main() {
    int ans = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &t[i]);
        ans += t[i];  //让ans初始为总和
    }
    for (int i = 2; i <= n / 3; ++i) //至少要留下3个雕像，可暴力的范围就缩小了三倍
    {
        if (n % i == 0) //当可以删除雕像后得到正多边形时
        {
            for (int k = 1; k <= i; ++k) //考虑从第k个开始等间隔融化雕像
            {
                int tem = 0;
                for (int j = k; j <= n; j += i)
                    tem += t[j];
                if (tem > ans)
                    ans = tem;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
