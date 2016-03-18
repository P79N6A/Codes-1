#include<iostream>

using namespace std;

void printDigit(int n)
{
	if(n<0)
		n=n*-1;
	if(n>=10)
		printDigit(n/10);
	cout<<n-n/10*10;
}

int main()
{
	int number;
	cout<<"Please enter a number:";
	while(cin>>number)
	{
		if(number<0)
	 		cout<<"-";
		printDigit(number);
		cout<<"\nPlease enter a number:";
	}
	return 0;
}
