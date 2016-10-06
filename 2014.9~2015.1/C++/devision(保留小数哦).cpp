#include<iostream>
#include<iomanip>

using namespace std;
int main(void)
{
	double a,b;
	int c=2;
	while(cin>>a>>b)
	{
		cout<<setprecision(c)<<"The result is:"<<a/b<<endl;
	}
	return 0;
}
