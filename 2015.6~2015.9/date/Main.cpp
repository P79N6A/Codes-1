#include<iostream>
#include"Dater.h"
using namespace std;

int main(int argc, char* argv[])
{
	int year, month, day;
	cout << "请输入日期（eg.2000 1 10）: ";
	cin >> year >> month >> day;

	Dater dater(year, month, day);

	if (dater.isRightDate())
	{
		cout << "该天为该年的第 " << dater.totalDays() << " 天。\n";
	}
	else
	{
		cout << "输入日期错误!\n";
	}
	return 0;
}
