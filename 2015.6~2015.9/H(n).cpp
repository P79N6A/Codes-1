#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

long long H(int n){
    ll res = 0;
    for (int i = n; i >= 1; --i)
    {
        ll ed = i, v = n / i;
        ll beg = (n / (v + 1)); //(n / (v + 1)): 哪个值最快到达 v + 1
        res += (ed - beg)*v;
        i = beg + 1;
    }
    return res;
}

int main()
{
    int n, t; cin >> t;
    while (t --)
    {
        cin >> n;
        cout << H(n) << '\n';
    }
    return 0;
}

