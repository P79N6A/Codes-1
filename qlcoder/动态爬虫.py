#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/11/18 14:03
# @Author  : GooZy
import hashlib
from multiprocessing import Process
import requests
import time

base_link = 'http://www.qlcoder.com/train/spider3/%s'


def md5(data):
    m = hashlib.md5()
    m.update(data)
    return m.hexdigest()


def get_speed(name):
    wait = 5.0  # 初始等待1s
    mul_increase = True  # 是否倍增
    old_md5 = ''  # 上一次内容md5值
    first = True  # 第一次不比较md5值
    while True:
        content = requests.get(base_link % name)
        new_md5 = md5(content.content)
        if not first:
            if new_md5 == old_md5:
                if mul_increase:
                    wait = wait * 2
                else:
                    wait *= 1.1
            else:
                mul_increase = False
                wait /= 1.1
        old_md5 = new_md5
        print name, 'needs to wait', wait, 's'
        time.sleep(wait)
        first = False


if __name__ == '__main__':
    # 页面1大概是0.3秒刷新一次，页面2大概是1.3秒刷新一次
    # 直接忽略这两个，直接代码适配会会导致频率过大，ip暂时被封
    for i in range(3, 11):
        p = Process(target=get_speed, args=(i, ))
        p.start()
