#include<iostream>

using namespace std;
int main(void)
{
	int age1,age2;
	cout<<"What is your parents' age?"<<endl;
	cin>>age1>>age2;
	if(age1>100||age2>100)
		cout<<"How come?!"<<endl;
	else cout<<"Ok,their age are "<<age1<<" and "<<age2<<".\n";
	
	cin.ignore();
	cin.get();
	return 0;
}
