#include<cstdio>
#include<algorithm>
using namespace std;
int x, y, sum1, sum2;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, p;
    while (~scanf("%d%d", &n, &p))
    {
        sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            if ((x^y)%2 == 1) sum1 += x&y;
            else sum2 += x&y;
        }
        printf("%d\n", max(sum1, sum2));
    }
    return 0;
}
