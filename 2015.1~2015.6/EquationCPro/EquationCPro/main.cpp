//
//  main.cpp
//  EquationCPro
//
//  Created by Link on 15/7/6.
//  Copyright (c) 2015年 郭子尧. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double x1 = 0.0;
    double x2 = 0.0;
    
    cout << "ax*x+b*x+x = 0, 请输入a、b、c(eg:2.1 5.0 3.1)" << endl;
    cin >> a >> b >> c;
    
    double temp = 0.0;
    temp = b * b - 4 * a * c;
    
    int flag = 0;
    if (temp > 0)
    {
        flag = 1;
    }
    else if (temp == 0)
    {
        flag = 2;
    }
    else
    {
        flag = 3;
    }
    
    switch (flag)
    {
        case 1:
            x1 = (-b + sqrt(temp)) / (2 * a);
            x2 = (-b - sqrt(temp)) / (2 * a);
            cout << "有两个实根,分别为： " << "x1=" << x1 << ' ' << "x2=" << x2 << endl;
            break;
        case 2:
            x1 = (-b + sqrt(temp)) / (2 * a);
            cout << "有两个相等实根 ： " << "x1 = x2 = " << x1 << endl;
        case 3:
            cout << "该方程没有实根!" << endl;
    }
    return 0;
}
