#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/5/16 16:47
# @Author  : GUO Ziyao
class ObjectDict(dict):
    """
    Object like dict, every dict[key] can visite by dict.key

    If dict[key] is `Get`, calculate it's value.
    """
    def __getattr__(self, name):
        ret = self.__getitem__(name)
        if hasattr(ret, '__get__'):
            print(name, ret)
            return ret.__get__(self, ObjectDict)
        return ret


def how_dict():
    x = ObjectDict({
        'a': 1,
        'b': 'xxx',
        'c': list(),
        'd': ObjectDict({
            'e': 10
        }),
        10: 'f'
    })
    print(x.a)
    print(x.c)
    print(x.d)
    print(x.d.e)
    print(x.f)


if __name__ == '__main__':
    how_dict()