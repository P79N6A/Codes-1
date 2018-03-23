#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/3/23 08:40
# @Author  : GUO Ziyao
"""
下载超人前传所有剧本
"""
import os
import requests
import time
from pyquery import PyQuery as pq

START_URL = 'https://www.springfieldspringfield.co.uk/episode_scripts.php?tv-show=smallville&season=%s'


def index_page(dir_name, start_url):
    req = requests.get(start_url)
    response = pq(req.content)
    for each in response('a.season-episode-title').items():
        download(dir_name, 'https://www.springfieldspringfield.co.uk/' + each.attr.href, each.text())
        time.sleep(0.5)


def download(dir_name, link, title):
    req = requests.get(link)
    response = pq(req.text)
    text = response('div.scrolling-script-container').html().strip().split('<br/>')
    with open('%s/%s.txt' % (dir_name, title), 'wb') as f:
        for each in text:
            f.write(each.strip().encode('utf8') + '\n')
    print('Finish downloading %s/%s' % (dir_name, title))


if __name__ == '__main__':
    for i in range(1, 11):
        if not os.path.exists('Smallville/season%s' % i):
            os.mkdir('Smallville/season%s' % i)
        index_page('Smallville/season%s' % i, START_URL % i)
