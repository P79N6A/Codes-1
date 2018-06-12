#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/6/12 14:03
# @Author  : GUO Ziyao
# https://www.shiyanlou.com/challenges/3000
from ttl_property import ttl_property

class Book(object):
    def __init__(self):
        self._price = 100.0
        self._total = self._price * 10

    @ttl_property(ttl=2)
    def price(self):
        self._price = self._price * 0.8
        return self._price

    @ttl_property(ttl=2)
    def total(self):
        self._total = self._price * 10
        return self._total


if __name__ == '__main__':
    b = Book()
    print(b.price)
    print(b.total)
    import time
    time.sleep(3)
    print(b.price)
    print(b.total)
