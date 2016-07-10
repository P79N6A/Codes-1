#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	double H, U, D, F;
	while (scanf("%lf%lf%lf%lf", &H, &U, &D, &F) == 4)
	{
		if (H == 0)
			break;
		double decrease = U*F / 100;
		double high = 0;
		int days = 0, flag = 0;
		for (;;)
		{
			days++;
			high = high + U;
			if (high > H)
				break;
			U -= decrease;
			high -= D;
			if (high < 0 && U <= D)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("failure on day %d\n", days);
		else printf("success on day %d\n", days);
	}
	return 0;
}