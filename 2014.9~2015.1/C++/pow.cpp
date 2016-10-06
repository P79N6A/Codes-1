#include<iostream>

using namespace std;

double pow(double a,double b)
{
	if(b==0)
		return 1;
	else return a*pow(a,--b);
}

int main(void)
{
	double a,b;
	cout<<"What do you want to culculate?"<<endl;
	while(cin>>a>>b)
	{
		cout<<pow(a,b)<<endl;
	}
	return 0;
}
