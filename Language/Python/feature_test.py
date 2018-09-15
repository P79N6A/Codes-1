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

    def compute(value):
        for i in range(1, value + 1):
            if value % i == 0:
                yield i
    def test(value):
        import time
        time.sleep(0.1)

    start = time()
    threads = list()
    for each in [2139079, 1214759, 2139079, 1214759, 2139079, 1214759]:
        x = Thread(target=test, args=[each])
        x.start()
        threads.append(x)
    for each in threads:
        each.join()
    print(time() - start)


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
    with log_level(logging.DEBUG):
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
    from datetime import datetime
    from time import mktime
    now = datetime.now()
    print(mktime(now.timetuple()))


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
    # how_thread()
    # how_queue()
    # how_coroutine()
    # how_contextmanager()
    # how_copyreg()
    # how_datetime()
    # how_bisect()
    # how_decimal()
    how_cmp()