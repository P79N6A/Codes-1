#include <iostream>
using namespace std;

char a[60][60];
int b[4];

int main()
{
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 0; i < m - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
        {
            for (int k = i; k <= i + 1; ++k)
                for (int l = j; l <= j + 1; ++l)
                {
                    if (a[k][l] == 'f')
                        ++b[0];
                    if (a[k][l] == 'a')
                        ++b[1];
                    if (a[k][l] == 'c')
                        ++b[2];
                    if (a[k][l] == 'e')
                        ++b[3];
                }
            if (b[0] == 1 && b[1] == 1 && b[2] == 1 && b[3] == 1)
                ++ans;
            for (int i = 0; i < 4; ++i) b[i] = 0;
        }
    cout << ans << '\n';
    return 0;
}