#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    int n, a;
    while (cin >> n && n)
    {
        int tem = 0;
        for (int i = 0; i < n * n; ++i)
        {
            cin >> a;
            if (a == 1)
                ++tem;
        }
        cout << 2 * (n + tem / 2) << '\n';
    }
    return 0;
}