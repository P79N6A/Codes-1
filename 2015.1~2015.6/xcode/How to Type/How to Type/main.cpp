#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int t; cin >> t;
    while (t --)
    {
        string s;
        cin >> s;
        int ans = s.size();
        int lock = 0;
        for (int i = 0; s[i] ; ++i)
        {
            if (isupper(s[i]))
            {
                ++lock;
                if (lock == 1)
                    ++ans;
            }
            else {
                if (lock > 1 && (isupper(s[i + 1]) || i + 1 == s.size()))
                {
                    ++ans;
                }
                else if (lock > 1 && (islower(s[i + 1]) || i + 1 == s.size()))
                {
                    ++ans;
                    lock = 0;
                }
                else lock = 0;
            }
        }
        if (isupper(s[s.size() - 1]) && lock > 1)
            ++ans;
        cout << ans << '\n';
    }
    return 0;
}
