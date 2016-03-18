#include <iostream>
using namespace std;
int b[10];
bool is[10] ={0, 1, 1, 1, 0, 1, 0, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        int j = s[i] - '0';
        if (is[j])
            ++b[j];
        else {
            if (j == 4)
                ++b[3], b[2] += 2;
            if (j == 6)
                ++b[5], ++b[3];
            if (j == 8)
                ++b[7], b[2] += 3;
            if (j == 9)
                ++b[7], b[2] += 3, b[3] += 2, b[2] -= 2;
        }
    }
    for (int i = 9; i >= 2; --i)
    {
        while (b[i] --)
            cout << i;
    }
    cout << endl;
    return 0;
}
