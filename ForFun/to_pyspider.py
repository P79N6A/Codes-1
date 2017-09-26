#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : Guo Ziyao
# @File    : change_to_pyspider.py
# @Software: PyCharm

def change(filename):
    ret = ''
    in_class = False
    with open(filename, 'r') as f:
        for line in f:
            line = line.replace('response.xpath', 'html.xpath')
            line = line.replace('.extract()', '')
            line = line.replace('response.meta', 'response.save')
            line = line.replace('meta=', 'save=')
            line = line.replace('yield Request', 'self.crawl')
            if in_class and 'def' in line:
                ret += '    @config(age=1)\n'
            ret += line
            if in_class and '):' in line and 'def' in line:
                ret += '        html = response.etree\n'
            if 'on_start' in line:
                in_class = True
    with open(filename, 'w') as out:
        out.write(ret)

if __name__ == '__main__':
    change('code.py')