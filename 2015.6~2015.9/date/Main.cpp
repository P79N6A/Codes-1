#include<iostream>
#include"Dater.h"
using namespace std;

int main(int argc, char* argv[])
{
	int year, month, day;
	cout << "���������ڣ�eg.2000 1 10��: ";
	cin >> year >> month >> day;

	Dater dater(year, month, day);

	if (dater.isRightDate())
	{
		cout << "����Ϊ����ĵ� " << dater.totalDays() << " �졣\n";
	}
	else
	{
		cout << "�������ڴ���!\n";
	}
	return 0;
}
