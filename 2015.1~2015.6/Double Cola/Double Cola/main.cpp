#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pre = 5, sum = 5;
    while (sum - 5 < n)
    {
        pre = sum;
        sum *= 2;
    }
    int find = n - pre + 5;
    sum = sum - pre;
    int two = sum / 5;
    //cout << find << ' ' << sum << ' ' << two << endl;
    char name[5][10] = {"Howard", "Sheldon", "Leonard", "Penny", "Rajesh"};
    cout << name[(find % sum / two + (find % sum % two != 0)) % 5] << '\n';
    return 0;
}