#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    char s[10];
    sprintf(s, "%d", n);
    for (int i = strlen(s) - 1; i >= 0; --i)
    {
        if (s[i] >= '5')
        {
            cout << "-O|";
            for (int j = 0; j < s[i] - '5'; ++j)
                cout << 'O';
            cout << '-';
            for (int j = 0; j < 4 - (s[i] - '5'); ++j)
                cout << 'O';
            cout << '\n';
        }
        else {
            cout << "O-|";
            for (int j = 0; j < s[i] - '0'; ++j)
                cout << 'O';
            cout << '-';
            for (int j = 0; j < 4 - (s[i] - '0'); ++j)
                cout << 'O';
            cout << '\n';
        }
    }
    return 0;
}
