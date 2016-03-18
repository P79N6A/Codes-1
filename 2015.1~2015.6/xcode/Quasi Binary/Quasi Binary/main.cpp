#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    char ans = '0';
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] > ans)
            ans = s[i];
    }
    cout << ans << '\n';
    while (1)
    {
        bool flag = 1, first = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '0')
            {
                first = 0;
                cout << 1;
                flag = 0;
                s[i] -= 1;
            }
            else if (!first)
                cout << 0;
        }
        if (flag)
        {
            cout << '\n';
            break;
        }
        else cout << ' ';
    }
    return 0;
}
