#include "Dater.h"
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


Dater::Dater(int year, int month, int day) :mYear(year), mMonth(month), mDay(day)
{
}


Dater::~Dater()
{
}


bool Dater::isLeapYear()
{
	return ((mYear % 4 == 0 && mYear % 100 != 0) || (mYear % 400 == 0));
}


bool Dater::isRightDate()
{
	if (isLeapYear())
		days[2] = 29;
	if (mMonth < 1 || mMonth >12 || mDay > days[mMonth])
		return false;
	else return true;
}


int Dater::totalDays()
{
	int sumDays = mDay;
	for (int i = 1; i < mMonth; ++i)
	{
		if (i == 2 && isLeapYear())
			sumDays += days[i] + 1;
		else sumDays += days[i];
	}
	return sumDays;
}