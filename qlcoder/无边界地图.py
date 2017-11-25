#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/11/25 16:51
# @Author  : GooZy
import copy
import sys

auto = False  # 手动运行程序还是自动
times = 1000  # 进行轮次（自动运行须设置）
init_position = [(0, 0), (1, 0), (-1, 0), (-1, 1), (0, -1)]


def process(num):
    backup = copy.deepcopy(num)
    for pos in num:
        (x, y) = pos
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0: continue
                nx = x + i
                ny = y + j
                # 是否是生命体
                if (nx, ny) in num:
                    num[pos] += 1
                else:
                    # 可能是潜在的生命体产生点
                    cnt = 0  # 周围生命体个数
                    for k in range(-1, 2):
                        for l in range(-1, 2):
                            if k == 0 and l == 0: continue
                            bnx = nx + k
                            bny = ny + l
                            if (bnx, bny) in num:
                                cnt += 1
                    if cnt == 3:
                        backup[(nx, ny)] = 0
    for k, v in num.items():
        if v < 2 or v > 3:
            backup.pop(k)
    return backup


def show_map(num):
    sys.stdout.write('\033[2J')  # 控制台清屏
    max_x, min_x, max_y, min_y = 0, 0, 0, 0
    for k in num:
        x, y = k
        max_x = max(max_x, x)
        min_x = min(min_x, x)
        max_y = max(max_y, y)
        min_y = min(min_y, y)
    for i in range(min_x, max_x + 1):
        for j in range(min_y, max_y + 1):
            if (i, j) in num:
                sys.stdout.write('O')
            else:
                sys.stdout.write('-')
        sys.stdout.write('\n')


def begin():
    num = dict()  # 点周围有多少个生命体
    for each in init_position:
        num[each] = 0
    rnd = 0  # 迭代次数
    mx = 0  # 最大值
    mx_rnd = 0  # 最大轮次
    while True:
        print('迭代次数：' + str(rnd))
        print('存活数：' + str(len(num)))
        if len(num) > mx:
            mx = len(num)
            mx_rnd = rnd
        if auto:
            num = process(num)
            if rnd == times:
                break
        else:
            show_map(num)  # 显示地图。仅在控制台运行程序可查看效果
            judge = raw_input('是否进行下一轮？(按任意键继续，q退出)')
            if judge.lower() == 'q':
                break
            num = process(num)
        rnd += 1
    print('进过了%s轮' % rnd)
    print('最大存活为第%s轮，数量为%s' %(mx_rnd, mx))


if __name__ == '__main__':
    begin()