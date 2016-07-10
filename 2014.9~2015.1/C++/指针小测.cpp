#include<iostream>

using namespace std;

int main(void)
{
	int x=0;
	int *p_int=&x;
	int **p_p_int=&p_int;
	*p_int=12;
	**p_p_int=25;
	p_int=12;
	*p_p_int=3;
	p_p_int=27;
	cout<<x<<" "<<p_p_int<<" "<<p_int<<endl;
	cin.get();
	return 0;
}
