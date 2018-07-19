#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess


YAO_LOGIN = 'ssh guoziyao@%s'
TIGER_LOGIN = 'ssh tiger@%s'

name_list = ['dev', 'dev2', 'pyspider0', 'pyspider1', 'metis_test', 'flow0', 'flow1', 'selenium']

ip_address = {
    'dev': '',
    'dev2': '',
    'pyspider0': '',
    'pyspider1': '',
    'metis_test': '',
    'flow0': '',
    'flow1': '',
    'selenium': '',
}


def login(target):
    if target in ['dev', 'dev2']:
        subprocess.call(YAO_LOGIN % (ip_address[target]), shell=True)
    else:
        subprocess.call(TIGER_LOGIN % (ip_address[target]), shell=True)


if __name__=='__main__':
    print('Plz choose your target machine.')
    for index, each in enumerate(name_list):
        print('%d: %s = %s' %(index, each, ip_address[each]))
    x = input()
    login(name_list[int(x)])
