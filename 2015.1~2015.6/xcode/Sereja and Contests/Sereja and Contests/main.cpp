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

const int MAXN = 4010;

int flag[MAXN];

int main() {
    int x, k; cin >> x >> k;
    for (int i = 0; i < k; ++i)
    {
        int op, a, b;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            flag[a] = 1;
            flag[b] = -1;
        }
        else
        {
            cin >> a;
            flag[a] = 1;
        }
    }
    int mx = 0, mi = 0;
    for (int i = 1; i < x; ++i)
        if (!flag[i])
            ++mx;
    for (int i = x - 1; i > 1; --i)
        if (!flag[i] && !flag[i - 1])
        {
            ++mi;
            flag[i - 1] = 1;
        }
    cout << mx - mi << ' ' << mx << '\n';
    return 0;
}
