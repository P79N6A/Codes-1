#ifndef EXPR_H
#define EXPR_H
#include<iostream>
using namespace std;

//操作数栈
typedef struct StackNodeOPND
{
	double value;
	StackNodeOPND *next;
}*OPND;

//初始化数栈
int init(OPND &opnd);
//操作数入栈
int push(OPND &opnd, const double value);
//操作数出栈
int pop(OPND &opnd, double &value);
//获得栈顶操作数
int getTop(OPND &opnd, double &value);
//判断栈是否为空
int isEmpty(OPND &opnd);


//操作符栈
typedef struct StackNodeOPTR
{
	char op;
	StackNodeOPTR *next;
}*OPTR;

//初始化符栈
int init(OPTR &optr);
//操作符入栈
int push(OPTR &optr, const char op);
//操作符出栈
int pop(OPTR &optr, char &op);
//获得栈顶操作符
int getTop(OPTR &optr, char &op);
//判断栈是否为空
int isEmpty(OPTR &optr);


//解析表达式
double parse(const char expr[]);

#endif