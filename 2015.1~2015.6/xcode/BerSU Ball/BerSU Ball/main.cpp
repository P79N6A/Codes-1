#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 111;

int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for (int j = 0; j < m; ++j)
        cin >> b[j];
    sort(a, a + n);
    sort(b, b + m);
    int cnt1 = 0, cnt2 = 0, ans = 0;
    while (cnt1 < n && cnt2 < m)
    {
        int diff = a[cnt1] - b[cnt2];
        if (-1 <= diff && diff <= 1)
        {
            ++ans;
            ++cnt1;
            ++cnt2;
        }
        else if (diff > 1)
        {
            ++cnt2;
        }
        else if (diff < -1)
        {
            ++cnt1;
        }
    }
    cout << ans << '\n';
    return 0;
}
