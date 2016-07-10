//�Ƚ϶���ʽ���ַ��������ʱ��


#include<stdio.h>
#include<math.h>
#include<time.h>
#define MAX 100
#define MAXK 1e5

//ֱ�ӷ�
void zhijie(int n, double *a, double x)
{
	double p = a[0];
	for (int i = 1; i <=n; i++)
		p += a[i] * pow(x, i);
}
//�ؾ���
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
	printf("����X:");
	while (scanf("%lf", &x) == 1)
	{
		//ֱ�ӷ�
		start = clock();
		for (int i = 1; i <= MAXK; i++)
			zhijie(MAX, a, x);
		end = clock();
		printf("1.%d\n", end);
		printf("ֱ�ӷ���%6.2e s\n", (double)(start - end) / CLK_TCK / MAXK);
		//�ؾ���
		start = clock();
		for (int i = 1; i <= MAXK; i++)
			qinjiu(MAX, a, x);
		end = clock();
		printf("2.%d\n", end);
		printf("�ؾ��أ�%6.2e s\n", (double)(start - end) / CLK_TCK / MAXK);

		printf("����X:");
	}
	return 0;
}
