#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 310;
int a[MAXN];
char s[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (s[j][i] == '1' && s[i][k] == '1')
                    s[j][k] = '1';
    
    for (int i = 0; i < n; ++i)
    {
        int mi = a[i]; //记录最小值
        int p = i;     //记录最小值对应的坐标
        for (int j = 0; j < n; ++j)
        {
            if (s[i][j] == '1' && mi > a[j] && p < j)  //值小，且排在后面的点
            {
                mi = a[j];
                p = j;
            }
        }
        swap(a[i], a[p]);
    }
    for (int i = 0; i < n - 1; ++i)
        printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    return 0;
}
