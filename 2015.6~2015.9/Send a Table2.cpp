#include<iostream>
using namespace std;
const int INF = 0x7f7f7f7f, MAXN = 50001;
int phi[MAXN], n;

void init()
{
    for (int i = 2; i < MAXN; ++i) if(!phi[i])
    {
        for (int j = i; j < MAXN; j += i)
        {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    for (int i = 2; i < MAXN; ++i)
        phi[i] += phi[i - 1];
}

int main()
{
    init();
    while (cin >> n && n)
    {
        cout << phi[n] * 2 + 1 << '\n';
    }
    return 0;
}
