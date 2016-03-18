#include<cstdio>
#include<iostream>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;

int num[MAXN];

int main()
{
    int n, k, p, x, y, sum = 0, big = 0, small = 0; // big: 大于等于的数 small:小于的数
    cin >> n >> k >> p >> x >> y;
    for (int i = 0; i < k; ++i)
    {
        cin >> num[i];
        sum += num[i];
        if (num[i] < y) ++small;
        else ++big;
    }

    // n - k:代表big超过所需要的一半的情况
    sum += min(n - k, max(0, n / 2 - small)) + max(0, (n / 2 + 1 - big)) * y;

    if (sum > x || small > n / 2) cout << -1;
    else
    {
        for (int i = 0; i < max(0, (n / 2 + 1 - big)); ++i) cout << y << ' ';
        for (int i = 0; i < min(n - k, max(0, n / 2 - small)); ++i)
        {
            cout << 1;
            if (i != n / 2 - small - 1) cout << ' ';
        }
    }
    cout << '\n';
    return 0;
}
