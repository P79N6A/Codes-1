#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int ans = 0;
    while (n && m && n + m >= 3)
    {
        ++ans;
        if (m >= n)
        {
            m -= 2; n -= 1;
        }
        else {
            n -= 2; m -= 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
