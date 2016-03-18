#include<iostream>
#include<string>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 111;

bool ok[2][MAXN];

int main()
{
    string digit;
    ll a, b, num = 0;
    cin >> digit >> a >> b;
    for (int i = 0; i < digit.length(); ++i) {
        ll cur = digit[i] - '0';
        num = (((num % a) * (10 % a)) % a + cur % a) % a;
        if (!num) ok[0][i] = 1;
    }

    num = 0;
    int base = 1;
    for (int i = digit.length() - 1; i >= 0; --i) {
        ll cur = digit[i] - '0';
        num = (((cur % b) * (base % b)) %b + num % b) % b;
        if (!num && cur) ok[1][i] = 1;
        base = (base * 10) % b;
    }

    for (int i = 1; i < digit.length(); ++i) {
        if (ok[0][i - 1] && ok[1][i]) {
            cout << "YES\n";
            for (int j = 0; j <= i - 1; ++j) cout << digit[j];
            cout << '\n';
            for (int j = i; j < digit.length(); ++j) cout << digit[j];
            cout << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
