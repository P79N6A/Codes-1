#include<cmath>
#include<iostream>
using namespace std;
const double eps = 1e-10;
const int MAXN = 4;
int number[MAXN];

bool search(int n)
{
    if (n==1)
    {
        if (fabs(number[0] - 24.0) < eps)
            return true;
        else
            return false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double a = number[i], b = number[j];   //取出两个数
                number[j] = number[n - 1];    //将最后一个数提到前面（因为后期只遍历n - 1个数
            
                number[i] = a + b;
                if (search(n - 1)) return true;
            
                number[i] = a - b;
                if (search(n - 1)) return true;
                
                number[i] = a * b;
                if (search(n - 1)) return true;
            
                number[i] = a / b;
                if (search(n - 1)) return true;
            
                number[i] = a;   //恢复
                number[j] = b;
            }
        }
    }
    return false;
} 
int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        for (int i = 0; i < 4; i++)
            cin >> number[i];
        if (search(4))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}