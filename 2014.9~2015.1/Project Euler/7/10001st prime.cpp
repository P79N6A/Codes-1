#include <iostream>
using namespace std;

bool isprime(int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int k = 0;
	for (int i = 2;; i++)
	{
		if (isprime(i))
		{
			k++;
			//cout<<k<<"," << i << endl;
			//cin.get();
		}
		if (k == 10001)
		{
			cout << i << endl;
			break;
		}
	}
	cin.get();
	return 0;
}
