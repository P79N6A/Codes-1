#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/7/19 13:49
# @Author  : GUO Ziyao
# py2
import json
import requests
import random
import urllib
import hashlib
from pyquery import PyQuery as pq


key = ''
app = '02192414c0517e3f'
auth_key = ''
url = 'http://openapi.youdao.com/api'
from_lang = 'EN'
to_lang = 'zh-CHS'


def report_today():
    req = requests.get('https://www.brainyquote.com/quote_of_the_day')
    doc = pq(req.text)
    data = {
        'text': doc('a.oncl_q > img').attr('alt')
    }
    q = data['text']
    name = q.split('-')[-1].strip().replace(' ', '%20')
    salt = random.randint(1, 65536)
    sign = app + q + str(salt) + auth_key
    m1 = hashlib.md5()
    m1.update(sign)
    sign = m1.hexdigest()
    api_url = url + '?appKey=' + app + '&q=' + urllib.quote(
        q) + '&from=' + from_lang + '&to=' + to_lang + '&salt=' + str(
        salt) + '&sign=' + sign
    result = requests.get(api_url).json()
    if result['translation']:
        data['text'] = data['text'] + u'（%s）' % result['translation'][0]
    data['text'] += u"\nhttps://www.google.com.hk/search?q=%s\nhttps://www.baidu.com/s?ie=UTF-8&wd=%s" % (name, name)
    requests.post(key, data=json.dumps(data))


if __name__ == '__main__':
    report_today()