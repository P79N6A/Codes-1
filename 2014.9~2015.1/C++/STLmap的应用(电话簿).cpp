#include<map>
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	map<string,string> list;
	string name;
	cout<<"please enter a name"<<endl;
	cin>>name;
	cout<<"please enter it's telephone number"<<endl;
	cin>>list[name];
	cout<<name<<"'s phonenumber is "<<list[name]<<"."<<endl;
	cin.ignore();
	cin.get();
	return 0;
}
