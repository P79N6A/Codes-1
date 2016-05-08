#include<iostream>

using namespace std;

int main()
{
    int n, x, m; cin >> n;
    while (n --) {
        int sum = 0;
        cin >> m;
        while (m --) cin >> x, sum += x;
        cout << sum << '\n';
        if (n) cout << '\n';
    }
    return 0;
}

