#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess
from collections import OrderedDict


YAO_LOGIN = 'ssh guoziyao@%s'
TIGER_LOGIN = 'ssh tiger@%s'

ip_address = OrderedDict({
    'dev': '',
    'dev2': '',
    'pyspider00': '',
    'pyspider01': '',
    'pyspider10': '',
    'pyspider11': '',
    'flow0': '',
    'flow1': '',
    'selenium': '',
})


def login(target):
    if target in ['dev', 'dev2']:
        subprocess.call(YAO_LOGIN % (ip_address[target]), shell=True)
    else:
        subprocess.call(TIGER_LOGIN % (ip_address[target]), shell=True)


if __name__=='__main__':
    print('Plz choose your target machine.')
    name_list = list()
    for k, v in ip_address.items():
        print('%d: %s = %s' %(len(name_list), k, v))
        name_list.append(k)
    x = input()
    login(name_list[int(x)])
