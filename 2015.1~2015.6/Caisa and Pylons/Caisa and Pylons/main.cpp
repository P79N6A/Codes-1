#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    while (n --)
    {
        int x;
        cin >> x;
        if (ans < x) ans = x;
    }
    cout << ans << '\n';
    return 0;
}