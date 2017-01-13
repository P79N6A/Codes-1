#include"Expr.h"
#include<cstdlib>
#include<cstdio>

//初始化数栈
int init(OPND &opnd)
{
	//销毁链表元素
	while (opnd != NULL)
	{
		//删除旧节点
		OPND temp = opnd;
		opnd = temp->next;
		free(temp);
	}
	opnd = NULL;
	return 0;
}

//操作数入栈
int push(OPND &opnd, const double value)
{
	//新增节点，栈点上移
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

//操作数出栈
int pop(OPND &opnd, double &value)
{
	if (opnd == NULL) //空栈
	{
		return -1;
	}
	//弹出操作数
	value = opnd->value;

	//删除旧节点
	OPND temp = opnd;
	opnd = temp->next;
	free(temp);


	return 0;
}

//获得栈顶操作数
int getTop(OPND &opnd, double &value)
{
	if (opnd == NULL)
	{
		return -1;
	}
	value = opnd->value;
	return 0;
}

//判断栈是否为空
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


//初始化符栈
int init(OPTR &optr)
{
	//销毁链表元素
	while (optr != NULL)
	{
		//删除旧节点
		OPTR temp = optr;
		optr = temp->next;
		free(temp);
	}
	optr = NULL;
	return 0;
}

//操作符入栈
int push(OPTR &optr, const char op)
{
	//新增节点，栈点上移
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

//操作符出栈
int pop(OPTR &optr, char &op)
{
	if (optr == NULL) //如果是空栈
	{
		return -1;
	}
	//弹出操作数
	op = optr->op;

	//删除旧节点
	OPTR temp = optr;
	optr = temp->next;
	free(temp);


	return 0;
}

//获得栈顶操作符
int getTop(OPTR &optr, char &op)
{
	if (optr == NULL)
	{
		return -1;
	}
	op = optr->op;
	return 0;
}

//判断栈是否为空
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


//判断符号优先级
char precede(char a, char b)
{
	char priorTable[6][6] = //运算符间关系存入数组
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


//计算表达式
double calc(double a, char theta, double b)
{
	//运算
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
		std::cout << "表达式错误。\n"; exit(0);
	}


	return value;
}


//解析表达式
double parse(const char expr[])
{
	OPND opnd = NULL; //操作数栈
	OPTR optr = NULL; //操作符栈


	//初始化栈
	init(opnd);
	init(optr);


	for (int i = 0; expr[i]; ++i)
	{
		//读第一个字符
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


			//将token转为数字，压入操作数栈
			double value = atof(token);
			push(opnd, value);
		}
		else
		{
			//处理操作符
			//获得栈顶操作符，比较优先级
			char op = 0;
			getTop(optr, op);
			switch (precede(op, c))
			{
			case '<': //栈顶元素优先权大，入栈
				push(optr, c);
				break;
			case '=': //弹出括号
				pop(optr, c);
				break;
			case '>': //出栈并将结果入栈
			{
						  double a = 0, b = 0;
						  //弹出两个操作数和一个操作符
						  pop(opnd, a);
						  pop(opnd, b);
						  pop(optr, op);


						  //计算结果，入栈
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

	//最后计算一次
	if (!isEmpty(optr))
	{
		double a = 0, b = 0;
		char op = 0;
		//弹出两个操作数和一个操作符
		pop(opnd, b);
		pop(opnd, a);
		pop(optr, op);
		//计算结果，入栈
		push(opnd, calc(a, op, b));
	}

	//最终结果
	double value = 0;
	pop(opnd, value);


	return value;
}