#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1e3 + 11;

int main() {
	int n, x, small = 0, big = 0, org;
	scanf("%d%d", &n, &org);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &x);
		if (x > org) ++big;
		else ++small;
	}
	int ans = 0;
	while (small != 0) {
		if (big % 2 != 0) {
            small = (small - 1) / 2;
            big = big / 2 + 1;
        }
        else {
            big /= 2;
            small /= 2;
        }
        ++ans;
	}
	printf("%d\n", ans);
}