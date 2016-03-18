#include<iostream>
using namespace std;

int main()
{
    int n, k, m;
    while (cin >> n >> k >> m && (n||k||m))
    {
        int last = 0;
        for (int i = 2; i < n; ++i)
        {
            last = (last + k) % i;
        }
        cout << (last + m) % n + 1 << '\n';
    }
    return 0;
}

