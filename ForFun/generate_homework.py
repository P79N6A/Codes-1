#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/2/11 12:13
# @Author  : Guo Ziyao
from random import randint

mult = set()
div = set()

with open('problem.txt', 'w') as f:
    for i in range(1, 601):
        if i % 2 == 0:
            a = randint(10, 99)
            b = randint(10, 99)
            while (a, b) in mult:
                a = randint(10, 99)
                b = randint(10, 99)
            mult.add((a, b))
            mult.add((b, a))
            f.write(str(i) + ': ' + str(a) + ' x ' + str(b) + ' =\n')
            with open('result.txt', 'a') as r:
                r.write(str(i) + ': ' + str(a * b) + '\n')
        else:
            a = randint(100, 999)
            b = randint(1, 99)
            if a < b:
                a, b = b, a
            while (a, b) in div:
                a = randint(100, 999)
                b = randint(1, 99)
                if a < b:
                    a, b = b, a
            div.add((a, b))
            f.write(str(i) + ': ' + str(a) + ' ÷ ' + str(b) + ' =\n')
            with open('result.txt', 'a') as r:
                result = int(a / b)
                remainder = a - result * b
                r.write(str(i) + ': ' + str(result) + ((' ...... ' + str(remainder)) if remainder != 0 else '') + '\n')