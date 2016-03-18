#include<cmath>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    string pre = " + - # !";
    string mid = "01234567";
    string suf = " / / - .";
    srand((unsigned)time(NULL));
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << pre[rand() % 8];
            cout << mid[rand() % 7 + 1];
            cout << suf[rand() % 8];
            if (i != n - 1) cout << ',';
        }
        cout << '\n';
    }
    return 0;
}
