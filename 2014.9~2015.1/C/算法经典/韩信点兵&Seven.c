/*
 *���������Ǹ�����������3,5,7��������
 *���ԭ���Ŀ�����Сֵ������֪ԭ����С *��10��������100��
 */

#include<stdio.h>
#define N1 3
#define N2 5
#define N3 7
#pragma warning(disable:4996)

int main(void)
{
	int rema[3],sum,number;     //����remainder[i]�ֱ�Ϊsum����N1,N2,N3�������
	int na, nb, nc; 
	while (scanf("%d%d%d", &rema[0], &rema[1], &rema[2]) == 3)
	{
		for (int i = 1;; i++)
		{
			if ((i*N2*N3) % N1 == rema[0])
			{
				na = i*N2*N3; break;
			}
		}
		for (int i = 1;; i++)
		{
			if ((i*N1*N3) % N2 == rema[1])
			{
				nb =i*N1*N3; break;
			}
		}
		for (int i = 1;; i++)
		{
			if ((i*N2*N1) % N3 == rema[2])
			{
				nc = i*N2*N1; break;
			}
		}
		sum = na + nb + nc;
		for (int i = 1;; i++)
		{
			if (sum - N1*N2*N3 < 0)
			{
				number = sum;
				break;
			}
			else sum -= N1*N2*N3;
		}
		if (number >= 10 && number <= 100)
		{
			printf("%d\n", number);
		}
		else printf("No answer\n");
	}
	return 0;
}