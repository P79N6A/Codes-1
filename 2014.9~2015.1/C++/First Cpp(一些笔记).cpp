#include<iostream>
#include<string>  //to use the type of string

using namespace std;
int main(void)
{
	string first_name,second_name,full_name;
	//also can use char name[100];
	cout<<"Hey!I am alive!\n";
	cout<<"I am alive again!"<<endl;
	cout<<"What is your first name?"<<endl;
	cin>>first_name;
	cout<<"What is your second name?"<<endl;
	getline(cin,second_name,'\n');// read the string before character"\n"
	full_name=first_name+" "+second_name; //It can be used to connect more easily than C
	cout<<"Hello!"+full_name
	<<endl; //sultry C++.Sentence can be separated easily.
	cin.ignore(); //ignore the input at a time
	cin.get(); //to get a character
	return 0;
}
