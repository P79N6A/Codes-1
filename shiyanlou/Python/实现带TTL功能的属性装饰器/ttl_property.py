# -*- coding:utf-8 -*-

from time import time

class ttl_property(object):
    def __init__(self, ttl=None):
        self.ttl = ttl

    def __call__(self, func):
        self.func = func
        return self

    def __get__(self, instance, owner):
        name = self.func.__name__
        temp = instance.__dict__
        if temp.get(name):
            value, last_time = temp[name]
            if self.ttl is None or time() - last_time > self.ttl:
                temp[name] = (self.func(instance), time())
        else:
            temp[name] = (self.func(instance), time())
        return temp[name][0]

    def __set__(self, instance, value):
        instance.__dict__[self.func.__name__] = (value, time())
