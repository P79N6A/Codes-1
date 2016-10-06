#include <iostream>
using namespace std;
typedef long long ll;

ll f(ll q)
{
    return q * (q - 1) / 2;
}

int main() {
    ll n, m; cin >> n >> m;
    ll minf = n / m, left = n - minf * m;
    cout << (m - left) * f(minf) + left * f(minf + 1) << ' ';
    cout << f(n - m + 1) << '\n';
    return 0;
}
