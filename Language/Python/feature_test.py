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

    class BeDict(object):
        def __init__(self, a=1, b='b'):
            self.a = a
            self.b = b
    x = BeDict()
    print(x.__dict__)


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
    class Grade(object):
        def __init__(self):
            self._value = 0

        def __get__(self, instance, owner):
            return self._value

        def __set__(self, instance, value):
            if not (0 <= value <= 100):
                raise ValueError('out of range')

    class Exam(object):
        def __init__(self):
            self.math_grade = Grade()
            self.english_grade = Grade()

    first = Exam()
    second = Exam()
    first.math_grade = 10
    second.math_grade = 20
    print(first.math_grade, second.math_grade)


def how_try():
    try:
        print(1)
        # x = 10 / 0
        return 10
    except Exception as ex:
        print(2)
    else:
        print(3)


len = 10
def how_closures():
    x = 'abc'

    def sort_priority(numbers, group):
        found = False

        def helper(x):
            if x in group:
                global found
                found = True  # not affect the outer variable
                return (0, x)
            return (1, x)
        numbers.sort(key=helper)
        return found
    print(sort_priority([1, 2, 3], [1]))


def how_collections():
    import collections
    Point = collections.namedtuple('Point', ('x', 'y'))
    p = Point(1, 2)
    print(p[0], p.x)


def inc(num):
    num = 2
    if num > 0:
        num = 3
    print('nnn')
    print(num)


def how_class():
    class A(object):
        def __init__(self):
            self.__value = 5

        def get_value(self):
            return self.__value

    class B(A):
        def __init__(self):
            super(A, self).__init__()
            self.__value = 10

        def get_x(self):
            return self.__value

    t = B()
    print(t.__dict__)
    print(t.get_x())
    print(t.get_value())


def how_thread():
    from threading import Thread
    from time import time

    class A(object):
        total = 0

    def compute(value):
        for i in range(1, value + 1):
            if value % i == 0:
                yield i
    def test(value):
        import time
        time.sleep(0.1)
    def add(value):
        for i in range(10000):
            value.total += 1
            import time
            time.sleep(.0001)

    start = time()
    a = A()
    threads = list()
    for each in [2139079, 1214759, 2139079, 1214759, 2139079, 1214759]:
        x = Thread(target=add, args=[a])
        x.start()
        threads.append(x)
    for each in threads:
        each.join()
    print(time() - start)
    print(a.total)


def how_queue():
    from queue import Queue
    q = Queue()
    q.get()


def how_coroutine():
    def my_gen():
        current = yield
        while True:
            print('I am in')
            print(current)
            value = yield current
            print(current, value)
            print('compare')
            current = min(value, current)

    x = my_gen()
    next(x)
    print(x.send(4))
    print('First Round Done.')
    print(x.send(2))
    print('Second Round Done.')
    print(x.send(3))


def how_contextmanager():
    from contextlib import contextmanager
    import logging
    import time
    def debug():
        logging.error('begin')
        logging.error('error')
        logging.warn('warn')
        logging.info('info')
        logging.debug('debug')
    @contextmanager
    def log_level(level):
        print('Begin')
        logger = logging.getLogger()
        old_level = logger.getEffectiveLevel()
        logger.setLevel(level)
        try:
            yield
        finally:
            logger.setLevel(old_level)
    with log_level(logging.ERROR):
        debug()
        debug()


def how_copyreg():
    import copyreg
    class GameState(object):
        def __init__(self, a=1, b=2, c=3):
            self.a = a
            self.b = b
            self.c = c

    def unpickle_game_states(kwargs):
        return GameState(**kwargs)
    def pickle_game_state(game_state):
        kwargs = game_state.__dict__
        return unpickle_game_states, (kwargs, )
    copyreg.pickle(GameState, pickle_function=pickle_game_state)


def how_datetime():
    from datetime import datetime, timedelta
    from time import mktime
    now = datetime.now()
    print(mktime(now.timetuple()))
    base_date = datetime.today().date() - timedelta(days=1)
    date_list = list()
    for i in range(28, -1, -7):
        date_list.append(str(base_date - timedelta(days=i)))
    import bisect
    print(date_list)
    index = bisect.bisect_left(date_list, '2018-12-26')
    print(index)
    print(date_list[index])


def how_bisect():
    import bisect
    x = list(range(1, 1000, 2))
    print(x.index(333))
    print(x[bisect.bisect_left(x, 334)])


def how_decimal():
    from decimal import Decimal, ROUND_UP
    x = Decimal('0.003')
    print(x.quantize(Decimal('0.01'), rounding=ROUND_UP))


def how_cmp():
    class FlagSource(object):
        def __init__(self, _name, _priority):
            self.name = _name
            self.priority = _priority

        def __le__(self, other):
            return self.priority >= other.priority

        def __eq__(self, other):
            return self.priority == other.priority

        def __lt__(self, other):
            return self.priority > other.priority

    source1 = FlagSource('a', 3)
    source2 = FlagSource('b', 1)
    source3 = FlagSource('c', 3)
    print(source1 <= source3)
    print(source1 >= source2)


def how_redis():
    from redis import StrictRedis
    client = StrictRedis()
    key_list = ['key_' + str(i) for i in range(10)]
    client.delete(*key_list)
    client.zrem('name', *key_list)
    client.hdel('name', 'value', *key_list)
    client.lrem('name', count=0, value=10)
    client.zrange('name', 0, 0, withscores=True)
    client.zremrangebyrank()
    client.zincrby()
    client.zadd()
    client.zinterstore()
    client.mget()
    client.mset()
    pipe = client.pipeline()
    pipe.multi()
    client.zrevrangebyscore()
    client.blpop()


def how_inspect():
    import inspect
    def test(xx, hello='hh'):
        print(hello)

    print(inspect.getfullargspec(test))


def how_base64():
    import base64
    import hexdump
    data = "k1T0JZKxCM04CzK0CzmyDW=="  # 010-62682929
    data = "ffPLHJO1CJi0CzW4DNiz"  # 15164388463
    d_data = base64.b64decode(data)
    hexdump.hexdump(d_data)


def how_nametuple():
    from collections import namedtuple
    import inspect
    x = namedtuple('FullArgSpec', 'args varargs varkw defaults '
                       'kwonlyargs kwonlydefaults')
    print(x._make(inspect.getargspec(how_base64) + ([], None)))


def how_metaclass():
    from abc import ABCMeta, abstractmethod
    from six import add_metaclass

    @add_metaclass(ABCMeta)
    class EventBus(object):
        """事件总线接口"""

        @abstractmethod
        def publish(self, event):
            """ 发布事件接口 """
            pass

        @abstractmethod
        def register(self, listener):
            """注册listener接口"""
            pass

        @abstractmethod
        def unregister(self, listener):
            """取消注册listener接口"""
            pass

    class Test(EventBus):
        pass

    test = Test()


if __name__ == '__main__':
    # how_dict()
    # how_zip()
    # how_fe()
    # how_descriptor()
    # how_try()
    # how_closures()
    # how_collections()
    # inc(-1)
    # how_class()
    how_thread()
    # how_queue()
    # how_coroutine()
    # how_contextmanager()
    # how_copyreg()
    # how_datetime()
    # how_bisect()
    # how_decimal()
    # how_cmp()
    # how_redis()
    # how_inspect()
    # how_base64()
    # how_nametuple()
    # how_metaclass()
