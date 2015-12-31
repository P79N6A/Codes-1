#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 1e4 + 111;

int num[MAXN];

int main()
{
    int n, m, d; cin >> n >> m >> d;
    int up = n * m;
    for (int i = 0; i < up; ++i) cin >> num[i];
    sort(num, num + up);
    int targe = num[up / 2];
    int ans = 0;
    for (int i = 0; i < up; ++i) {
        if ((targe - num[i]) % d) {puts("-1"); return 0;}
        ans += abs(targe - num[i]) / d;
    }
    cout << ans << '\n';
    return 0;
}
