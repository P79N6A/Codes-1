#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t, n, k; cin >> t;
    for (int kase = 1; kase <= t; ++kase)
    {
        cout << "Case " << kase << ": ";
        cin >> n >> k;
        if (n <= k || (n % 2 && k == 1)) cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}
