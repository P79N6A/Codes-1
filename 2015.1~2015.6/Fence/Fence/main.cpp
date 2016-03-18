#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e6;
typedef long long ll;
int a[MAXN];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += a[i];
    int tem = sum;
    int ans = 1;
    for (int i = k; i < n; ++i)
    {
        tem += (a[i] - a[i - k]);
        //cout << tem << endl;
        if (tem < sum)
        {
            ans = i + 2 - k;
            sum = tem;
        }
    }
    printf("%d\n", ans);
    return 0;
}
