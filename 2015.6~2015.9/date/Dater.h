#pragma once
class Dater
{
public:
	Dater();
	Dater(int year, int month, int day);
	~Dater();

	bool isLeapYear();
	bool isRightDate();
	int totalDays();

private:
	int mYear;
	int mMonth;
	int mDay;
};

