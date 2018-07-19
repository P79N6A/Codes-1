#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess


YAO_LOGIN = 'ssh guoziyao@%s'
TIGER_LOGIN = 'ssh tiger@%s'

name_list = ['dev', 'dev2', 'pyspider0', 'pyspider1', 'metis_test', 'flow0', 'flow1', 'selenium']

ip_address = {
    'dev': '10.6.131.79',
    'dev2': '10.8.127.161',
    'pyspider0': '10.6.15.150',
    'pyspider1': '10.6.15.151',
    'metis_test': '10.6.15.137',
    'flow0': '10.12.22.137',
    'flow1': '10.12.22.133',
    'selenium': '10.15.63.98',
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
