#include<iostream>
using namespace std;

int main()
{
    int n; while (cin >> n)
    cout << (n-1)*n*n-(n-1)*(n-2)+(n*n-n)/2-(n-1)/2+1 << '\n';
    return 0;
}

