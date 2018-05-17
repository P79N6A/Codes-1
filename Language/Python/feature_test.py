#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/5/16 16:47
# @Author  : GUO Ziyao
class ObjectDict(dict):
    def __getattr__(self, name):
        ret = self.__getitem__(name)
        # if hasattr(ret, '__get__'):  # 意义不明。
        #     print(name, ret)
        #     return ret.__get__(self, ObjectDict)
        return ret


def how_dict():
    def hello():
        print('hello')

    x = ObjectDict({
        'a': 1,
        'b': 'xxx',
        'c': list(),
        'd': ObjectDict({
            'e': 10
        }),
        10: 'f',
        'g': hello,
        hello: '????',
    })
    print(x.a)
    print(x.c)
    print(x.d)
    print(x.d.e)
    # print(x.f)
    print(x.g)
    # print(x.hello)
    print(x[hello])


def how_zip():
    x = (x for x in range(4))
    y = (y for y in range(5, 12))
    import itertools
    for a, b in itertools.izip_longest(x, y):
        print(a, b)


def how_fe():
    for i in []:
        print('Never runs')
    else:
        print('For else block')


def how_descriptor():
    class RevealAccess(object):
        """A data descriptor that sets and returns values
           normally and prints a message logging their access.
        """

        def __init__(self, initval=None, name='var'):
            self.val = initval
            self.name = name

        def __get__(self, obj, objtype):
            print 'Retrieving', self.name
            return self.val

        def __set__(self, obj, val):
            print 'Updating', self.name
            self.val = val

    class A(object):
        x = RevealAccess()

    # A = A()
    print(A.x)
    A.x = 10
    print(A.x)


if __name__ == '__main__':
    how_dict()
    # how_zip()
    # how_fe()
    # how_descriptor()
