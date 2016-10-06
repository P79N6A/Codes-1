#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s, e;
    cin >> s >> e;
    int move1 = abs(s[0] - e[0]), move2 = abs(s[1] - e[1]);
    char m1, m2;
    if (s[0] >= e[0])
        m1 = 'L';
    else m1 = 'R';
    if (s[1] >= e[1])
        m2 = 'D';
    else m2 = 'U';
    int ans = max(move1, move2);
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i)
    {
        if (move1)
        {
            cout << m1;
            --move1;
        }
        if (move2)
        {
            cout << m2;
            --move2;
        }
        cout << '\n';
    }
    return 0;
}