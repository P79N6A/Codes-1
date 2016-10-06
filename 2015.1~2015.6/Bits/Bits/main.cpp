#include <iostream>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
    int n;
    ll l, r;
    cin >> n;
    while (n --)
    {
        cin >> l >> r;
        int k = 0;
        for (int i = 0; i <= 61; ++i)
        {
            if (pow(2, i) - 1 > r)
            {
                k = i;
                break;
            }
        }
        --k;
        ll ans = pow(2, k) - 1;
        while (1)
        {
            if (ans >= l)
                break;
            else {
                ans += 1;
                for (int i = 0; i < k; ++i)
                {
                    ans += pow(2, i);
                    if (ans > r)
                    {
                        ans -= pow(2, i);
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
