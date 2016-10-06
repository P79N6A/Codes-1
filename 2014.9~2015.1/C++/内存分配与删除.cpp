#include<iostream>

using namespace std;

int main(void)
{
	int *p=new int;
	int a=9;
	p=&a;
	cout<<*p<<endl;
	delete p;
	p=NULL;
	cin.get();
	return 0;
}
		
		
