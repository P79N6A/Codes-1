#ifndef EXPR_H
#define EXPR_H
#include<iostream>
using namespace std;

//������ջ
typedef struct StackNodeOPND
{
	double value;
	StackNodeOPND *next;
}*OPND;

//��ʼ����ջ
int init(OPND &opnd);
//��������ջ
int push(OPND &opnd, const double value);
//��������ջ
int pop(OPND &opnd, double &value);
//���ջ��������
int getTop(OPND &opnd, double &value);
//�ж�ջ�Ƿ�Ϊ��
int isEmpty(OPND &opnd);


//������ջ
typedef struct StackNodeOPTR
{
	char op;
	StackNodeOPTR *next;
}*OPTR;

//��ʼ����ջ
int init(OPTR &optr);
//��������ջ
int push(OPTR &optr, const char op);
//��������ջ
int pop(OPTR &optr, char &op);
//���ջ��������
int getTop(OPTR &optr, char &op);
//�ж�ջ�Ƿ�Ϊ��
int isEmpty(OPTR &optr);


//�������ʽ
double parse(const char expr[]);

#endif