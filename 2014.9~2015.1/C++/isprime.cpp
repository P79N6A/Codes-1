#include<iostream>

bool isprime(int n);
bool isde(int n);
using namespace std;

int main(void)
{
	int n;
	while(cin>>n)
	{
		for(int i=2;i<n;i++)
		{
			if(isprime(i))
				cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}

bool isprime(int n)
{
	if(isde(n))
		return false;
	else return true;
}

bool isde(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return true;
	}
	return false;
}
