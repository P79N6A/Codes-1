#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(void)
{
	int one=0,zero=0;
	srand(time(NULL));
	for(int i=0;i<1000;i++)
	{
		if(rand()%2==1)
			one++;44444444444444444444444444444444444444444
		else zero++;
	}
	cout<<"正面="<<one<<" "<<"反面="<<zero<<endl;
	cin.get();
	return 0;
}
