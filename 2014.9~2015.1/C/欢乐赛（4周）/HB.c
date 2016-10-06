#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main(void)
{
	double x1, x2, y1, y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)==4)
	{
		double ANS = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		double answer = sqrt(ANS);
		printf("%.2lf\n", answer);
	}
	return 0;
}