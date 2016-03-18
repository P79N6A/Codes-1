#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 11;

int a[MAXN];

bool judge(int l, int r)
{
    if (l > r)
        return 0;
    int max1 = max(a[l + 1], a[r]), max2 = max(a[l], a[r - 1]);
    if (max1 > max2)
        return 1;
    else if (max1 < max2)
        return 0;
    else {
        return judge(l + 2, r - 2);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        int sum1 = 0, sum2 = 0, p1 = 0, p2 = n - 1;
        while (p1 < p2)
        {
            if (judge(p1, p2))
            {
                sum1 += a[p2];
                --p2;
                if (a[p1] > a[p2])
                {
                    sum2 += a[p1];
                    ++p1;
                }
                else {
                    sum2 += a[p2];
                    --p2;
                }
            }
            else {
                sum1 += a[p1];
                ++p1;
                if (a[p1] > a[p2])
                {
                    sum2 += a[p1];
                    ++p1;
                }
                else {
                    sum2 += a[p2];
                    --p2;
                }
            }
        }
        printf("%d\n", abs(sum1 - sum2));
    }
    
    return 0;
}
