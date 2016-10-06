#include<iostream>
#include<bitset>
using namespace std;

int main()
{
    int t;
    long long x;
    bitset<32> a;
    cin >> t;
    while (t --) {
        cin >> x; a = x;
        cout << a << '\n';
    }
    return 0;
}
