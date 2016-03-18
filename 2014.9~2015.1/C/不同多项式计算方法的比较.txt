//比较多项式两种方法所需的时间


#include<stdio.h>
#include<math.h>
#include<time.h>
#define MAX 100
#define MAXK 1e5

//直接法
void zhijie(int n, double *a, double x)
{
	double p = a[0];
	for (int i = 1; i <=n; i++)
		p += a[i] * pow(x, i);
}
//秦九韶
void qinjiu(int n, double *a, double x)
{
	double p = a[MAX - 1];
	for (int i = n - 1; i > -1; i--)
		p += a[i - 1] + x * p;
}

int main(void)
{
	double a[MAX],start,end,x;
	for (int i = 0; i < MAX; i++)
		a[i] = (double)i;
	printf("%lf\n", MAXK);
	printf("输入X:");
	while (scanf("%lf", &x) == 1)
	{
		//直接法
		start = clock();
		for (int i = 1; i <= MAXK; i++)
			zhijie(MAX, a, x);
		end = clock();
		printf("1.%d\n", end);
		printf("直接法：%6.2e s\n", (double)(start - end) / CLK_TCK / MAXK);
		//秦九韶
		start = clock();
		for (int i = 1; i <= MAXK; i++)
			qinjiu(MAX, a, x);
		end = clock();
		printf("2.%d\n", end);
		printf("秦九韶：%6.2e s\n", (double)(start - end) / CLK_TCK / MAXK);

		printf("输入X:");
	}
	return 0;
}
