#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int num[100];

int main() {
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n; cin >> t;
    while (t --) {
        n = 26;
        int mi = 50;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            if (num[i]) {
                mi = min(num[i], mi);
                ++cnt;
            }
        }
        if (cnt == 1) {
            int ans = 0;
            for (int i = 2; i <= mi; ++i) ans += i - 1;
            cout << ans << '\n';
        }
        else if (cnt == 0 || mi == 1) cout << 0 << '\n';
        else cout << mi - 1 << '\n';
    }
}
