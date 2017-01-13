<<<<<<< HEAD
/*   
 *     Decimal number to binary number(practice)
 *             2014.11.29
 */

#include<stdio.h>
char itobs(int, char *);    //itobs=integer to binary string
void show_bsty(const char *);    //show binary string
void show_line(void);

int main(void)
{
	char binary_str[8 * sizeof(int)+1];    //¿¼ÂÇµ½½áÎ²¿Õ×Ö·û
	int number;
	show_line();
	puts("Enter integers and see them in binary.");
	puts("Non-numeric input to quit.");
	show_line();
	while (scanf_s("%d", &number) == 1)
	{
		itobs(number, binary_str);
		printf("%d in binary is: ",number);
		show_bsty(binary_str);
		show_line();
	}
	puts("Bye~Bye~");
	return 0;
}

char itobs(int number, char *p)
{
	int a = 8*sizeof(int);
	for (int i = a-1; i >= 0; i--, number >>= 1)
	{
		p[i] = (01 & number) + '0';              //Äæ×ÅÊäÈë
	}
	p[a] = '\0';
	return p;
}

void show_bsty(const char *p)
{
	int i = 0;
	while (p[i])
	{
		putchar(p[i]);
		if (++i % 4 == 0 && p[i])
			putchar('  ');
	}
	putchar('\n');
}

void show_line()
{
	for (int i = 0; i < 80; i++)
		printf("=");
=======
/*   
 *     Decimal number to binary number(practice)
 *             2014.11.29
 */

#include<stdio.h>
char itobs(int, char *);    //itobs=integer to binary string
void show_bsty(const char *);    //show binary string
void show_line(void);

int main(void)
{
	char binary_str[8 * sizeof(int)+1];    //¿¼ÂÇµ½½áÎ²¿Õ×Ö·û
	int number;
	show_line();
	puts("Enter integers and see them in binary.");
	puts("Non-numeric input to quit.");
	show_line();
	while (scanf_s("%d", &number) == 1)
	{
		itobs(number, binary_str);
		printf("%d in binary is: ",number);
		show_bsty(binary_str);
		show_line();
	}
	puts("Bye~Bye~");
	return 0;
}

char itobs(int number, char *p)
{
	int a = 8*sizeof(int);
	for (int i = a-1; i >= 0; i--, number >>= 1)
	{
		p[i] = (01 & number) + '0';              //Äæ×ÅÊäÈë
	}
	p[a] = '\0';
	return p;
}

void show_bsty(const char *p)
{
	int i = 0;
	while (p[i])
	{
		putchar(p[i]);
		if (++i % 4 == 0 && p[i])
			putchar('  ');
	}
	putchar('\n');
}

void show_line()
{
	for (int i = 0; i < 80; i++)
		printf("=");
>>>>>>> 0b60cd064a44b3785031935bf8a0220b4231fd24
}