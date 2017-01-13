#include"Expr.h"

int main(int argc, int argv[])
{
	//输出界面
	cout << "======== 表达式求值 ========\n";
	cout << "|1.支持四则运算：+ - * /   |\n";
	cout << "|2.支持括号（）            |\n";
	cout << "|3.支持浮点数              |\n";
	cout << "|请输入表达式，按回车结束。|\n";
	cout << "|例如：5*(9+8)             |\n";
	cout << "============================\n";

	//输入表达式
	char expr[256] = { 0 };
	cout << "请输入表达式：";
	cin >> expr;

	//输出结果
	cout << "结果：" << parse(expr) << '\n';

	return 0;
}