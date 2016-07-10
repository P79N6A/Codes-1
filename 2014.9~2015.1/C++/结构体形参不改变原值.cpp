#include<iostream>

using namespace std;

struct M_struct
{
	int x;
};

void updatestruct(M_struct a)
{
	a.x=10;
};
	

int main(void)
{
	M_struct a;
	a.x=5;
	updatestruct(a);
	cout<<a.x<<endl;
	cin.get();
	return 0;
}
	
