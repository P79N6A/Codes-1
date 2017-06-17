#include <iostream>
using namespace std;

const int MAXN = 1e3 + 11;

int main() {
	int n, m;
	int a[MAXN], b[MAXN];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int ans = 2e9;
	for (int i = 0; i < m - n; ++i) {
		int temp = 0;
		for (int j = 0; j < n; ++j) {
			temp += (b[i + j] - a[j]) * (b[i + j] - a[j]);
		}
		ans = min(ans, temp);
	}
	cout << ans << endl;
}