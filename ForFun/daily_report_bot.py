#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/7/19 13:49
# @Author  : GUO Ziyao
import json
import requests
from pyquery import PyQuery as pq


key = ''


def report_today():
    req = requests.get('https://www.brainyquote.com/quote_of_the_day')
    doc = pq(req.text)
    data = {
        'text': doc('a.oncl_q > img').attr('alt')
    }
    requests.post(key, data=json.dumps(data))


if __name__ == '__main__':
    report_today()