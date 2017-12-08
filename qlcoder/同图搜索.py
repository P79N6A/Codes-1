#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/12/3 17:33
# @Author  : Guo Ziyao
import glob
from PIL import Image
import imagehash

if __name__ == '__main__':
    base = '/Users/guoziyao/Desktop/CR/2/'
    target = '/Users/guoziyao/Desktop/CR/ok2/'
    count = dict()
    cnt = 0
    for each in glob.glob(target + '*'):
        cnt += 1
        value = int(each[each.rfind('/') + 1: each.rfind('.')])
        img = Image.open(each)
        h = imagehash.average_hash(img)
        count[h] = count.get(h, []) + [value]
    # for k, v in count.items():
    #     if len(v) > 1:
    #         for each in v:
    #             img = Image.open(target + str(each) + '.jpg')
    #             img.show()
    print cnt
    print len(count)
    sum = 0
    for each in glob.glob(base + '*'):
        img = Image.open(each)
        h = imagehash.average_hash(img)
        value = 0
        min_diff = 1e10
        for k, v in count.items():
            if abs(k - h) < min_diff:
                min_diff = abs(k - h)
                value = v[0]
        print each, value
        sum += value
    print sum