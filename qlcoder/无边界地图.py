#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/11/25 16:51
# @Author  : GooZy
import copy

times = 1000  # 进行轮次
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
        # judge = raw_input('是否进行下一轮？(按任意键继续，q退出)')
        num = process(num)
        rnd += 1
        if rnd == times:
            break
        # if judge.lower() == 'q':
        #     break
    print('进过了%s轮' % rnd)
    print('最大存活为第%s轮，数量为%s' %(mx_rnd, mx))


if __name__ == '__main__':
    begin()