#include"Expr.h"
#include<cstdlib>
#include<cstdio>

//��ʼ����ջ
int init(OPND &opnd)
{
	//��������Ԫ��
	while (opnd != NULL)
	{
		//ɾ���ɽڵ�
		OPND temp = opnd;
		opnd = temp->next;
		free(temp);
	}
	opnd = NULL;
	return 0;
}

//��������ջ
int push(OPND &opnd, const double value)
{
	//�����ڵ㣬ջ������
	OPND temp = (OPND)malloc(sizeof(StackNodeOPND));
	if (!temp)
	{
		return -1;
	}
	temp->value = value;
	temp->next = opnd;
	opnd = temp;
	return 0;
}

//��������ջ
int pop(OPND &opnd, double &value)
{
	if (opnd == NULL) //��ջ
	{
		return -1;
	}
	//����������
	value = opnd->value;

	//ɾ���ɽڵ�
	OPND temp = opnd;
	opnd = temp->next;
	free(temp);


	return 0;
}

//���ջ��������
int getTop(OPND &opnd, double &value)
{
	if (opnd == NULL)
	{
		return -1;
	}
	value = opnd->value;
	return 0;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(OPND &opnd)
{
	if (opnd == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//��ʼ����ջ
int init(OPTR &optr)
{
	//��������Ԫ��
	while (optr != NULL)
	{
		//ɾ���ɽڵ�
		OPTR temp = optr;
		optr = temp->next;
		free(temp);
	}
	optr = NULL;
	return 0;
}

//��������ջ
int push(OPTR &optr, const char op)
{
	//�����ڵ㣬ջ������
	OPTR temp = (OPTR)malloc(sizeof(StackNodeOPTR));
	if (temp == NULL)
	{
		return -1;
	}
	temp->op = op;
	temp->next = optr;
	optr = temp;
	return 0;
}

//��������ջ
int pop(OPTR &optr, char &op)
{
	if (optr == NULL) //����ǿ�ջ
	{
		return -1;
	}
	//����������
	op = optr->op;

	//ɾ���ɽڵ�
	OPTR temp = optr;
	optr = temp->next;
	free(temp);


	return 0;
}

//���ջ��������
int getTop(OPTR &optr, char &op)
{
	if (optr == NULL)
	{
		return -1;
	}
	op = optr->op;
	return 0;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(OPTR &optr)
{
	if (optr == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//�жϷ������ȼ�
char precede(char a, char b)
{
	char priorTable[6][6] = //��������ϵ��������
	{   
		//|+|  |-|  |*|  |/|  |(|  |)|
		{ '>', '>', '<', '<', '<', '>' },// +
		{ '>', '>', '<', '<', '<', '>' },// -
		{ '>', '>', '>', '>', '<', '>' },// *
		{ '>', '>', '>', '>', '<', '>' },// /
		{ '<', '<', '<', '<', '<', '=' },// (
		{ '>', '>', '>', '>', '>', '>' } // )
	}; 

	int x = -1, y = -1;
	char opr[] = "+-*/()";
	for (int i = 0; i < 6; ++i)
	{
		if (a == opr[i]) x = i;
		if (b == opr[i]) y = i;
	}


	return priorTable[x][y];
}


//������ʽ
double calc(double a, char theta, double b)
{
	//����
	double value = 0;
	switch (theta)
	{
	case '+':
		value = a + b; break;
	case '-':
		value = a - b; break;
	case '*':
		value = a * b; break;
	case '/':
		value = a / b; break;
	default:
		std::cout << "���ʽ����\n"; exit(0);
	}


	return value;
}


//�������ʽ
double parse(const char expr[])
{
	OPND opnd = NULL; //������ջ
	OPTR optr = NULL; //������ջ


	//��ʼ��ջ
	init(opnd);
	init(optr);


	for (int i = 0; expr[i]; ++i)
	{
		//����һ���ַ�
		char c = expr[i];
		if (c >= '0' && c <= '9' || c == '.')
		{
			char token[20] = { 0 };
			int j = 0;
			while (expr[i + j] >= '0' && expr[i + j] <= '9' || expr[i + j] == '.')
			{
				token[j] = expr[i + j];
				++j;
			}
			token[j] = '\0';
			i = i + j - 1;


			//��tokenתΪ���֣�ѹ�������ջ
			double value = atof(token);
			push(opnd, value);
		}
		else
		{
			//���������
			//���ջ�����������Ƚ����ȼ�
			char op = 0;
			getTop(optr, op);
			switch (precede(op, c))
			{
			case '<': //ջ��Ԫ������Ȩ����ջ
				push(optr, c);
				break;
			case '=': //��������
				pop(optr, c);
				break;
			case '>': //��ջ���������ջ
			{
						  double a = 0, b = 0;
						  //����������������һ��������
						  pop(opnd, a);
						  pop(opnd, b);
						  pop(optr, op);


						  //����������ջ
						  push(opnd, calc(a, op, b));
						  i--;
						  break;
			}
			default:
				push(optr, c);
				break;
			} // end switch
		}
	}

	//������һ��
	if (!isEmpty(optr))
	{
		double a = 0, b = 0;
		char op = 0;
		//����������������һ��������
		pop(opnd, b);
		pop(opnd, a);
		pop(optr, op);
		//����������ջ
		push(opnd, calc(a, op, b));
	}

	//���ս��
	double value = 0;
	pop(opnd, value);


	return value;
}