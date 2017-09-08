#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/8/27 17:23
# @Author  : Guo Ziyao
# @File    : nlp.py
# @Software: PyCharm
import re
import sys
from pyltp import Segmentor
from pyltp import NamedEntityRecognizer
from pyltp import Postagger
from html_get import http_request

reload(sys)
sys.setdefaultencoding('utf-8')

def filter_tags(htmlstr):
    # 先过滤CDATA
    re_cdata=re.compile('//<!\[CDATA\[[^>]*//\]\]>',re.I) #匹配CDATA
    re_script=re.compile('<\s*script[^>]*>[^<]*<\s*/\s*script\s*>',re.I)#Script
    re_style=re.compile('<\s*style[^>]*>[^<]*<\s*/\s*style\s*>',re.I)#style
    re_br=re.compile('<br\s*?/?>')#处理换行
    re_h=re.compile('</?\w+[^>]*>')#HTML标签
    re_comment=re.compile('<!--[^>]*-->')#HTML注释
    s=re_cdata.sub('',htmlstr)#去掉CDATA
    s=re_script.sub('',s) #去掉SCRIPT
    s=re_style.sub('',s)#去掉style

    s=re_br.sub('\n',s)#将br转换为换行
    s=re_h.sub('',s) #去掉HTML 标签
    s=re_comment.sub('',s)#去掉HTML注释
    #去掉多余的空行
    blank_line=re.compile('\n+')
    s=blank_line.sub('\n',s)
    s=replaceCharEntity(s)#替换实体
    return s


def replaceCharEntity(htmlstr):
    CHAR_ENTITIES = {'nbsp': ' ', '160': ' ',
                     'lt': '<', '60': '<',
                     'gt': '>', '62': '>',
                     'amp': '&', '38': '&',
                     'quot': '"', '34': '"', }

    re_charEntity = re.compile(r'&#?(?P<name>\w+);')
    sz = re_charEntity.search(htmlstr)
    while sz:
        entity = sz.group()  # entity全称，如&gt;
        key = sz.group('name')  # 去除&;后entity,如&gt;为gt
        try:
            htmlstr = re_charEntity.sub(CHAR_ENTITIES[key], htmlstr, 1)
            sz = re_charEntity.search(htmlstr)
        except KeyError:
            # 以空串代替
            htmlstr = re_charEntity.sub('', htmlstr, 1)
            sz = re_charEntity.search(htmlstr)
    return htmlstr

segmentor = Segmentor()  # 初始化实例
segmentor.load("/Users/guoziyao/repos/pyltp/ltp_data/cws.model")  # 加载模型
postagger = Postagger()  # 初始化实例
postagger.load("/Users/guoziyao/repos/pyltp/ltp_data/pos.model")  # 加载模型
recognizer = NamedEntityRecognizer()  # 初始化实例
recognizer.load("/Users/guoziyao/repos/pyltp/ltp_data/ner.model")  # 加载模型

def recgonize(url, tag):
    """
    :param url: 网址
    :param tag: 实体标记。Ni 机构名，Nh 人名，Ns 地名
    :return: 得到的结果
    """
    text = http_request(url)
    text = filter_tags(text).replace(' ', '')
    lines = text.split()

    result = []
    for line in lines:
        line = line.encode('utf-8')
        words = segmentor.segment(line)  # 分词
        postags = postagger.postag(words)  # 词性标注
        netags = recognizer.recognize(words, postags)  # 命名实体识别
        temp = ''
        for word, netag in zip(words, netags):
            # print word + '/' + netag
            if 'B-' + tag in netag:
                temp += word
            elif 'I-' + tag in netag:
                temp += word
            elif 'E-' + tag in netag:
                temp += word
                result.append(temp)
                temp = ''
    return result



# 清华分词
# import thulac
#
# thu1 = thulac.thulac()  #默认模式
# for i in res:
#     text = thu1.cut(i, text=True)
#     print text

# 语言云API
# args = {
#     'api_key': '41x3R7G1P5zfkZ0TcLosoW3GVc4qrpbP9Ehecvsl',
#     'pattern': 'ner',
#     'format': 'plain',
# }
#
# url = 'http://api.ltp-cloud.com/analysis/'
#
# for i in range(100):
#     args['text'] = res[i]
#     result = requests.post(url, args)
#     print result.text
#
#
url = 'http://www.bjxinxiangyin.com/'
for ans in recgonize(url, 'Ni'): print ans
for ans in recgonize(url, 'Ns'): print ans
#
# out = open('result.txt', 'w')
# tags = ['Ni', 'Ns']
# with open('failed.log', 'r') as f:
#     for index, line in enumerate(f):
#         if 'None' != line.split(',')[0]:
#             continue
#         url = 'http://' + line.split(',')[1][: -1]
#         out.write(str(index) + ': ' + url + '\n')
#         for tag in tags:
#             out.write(tag + ' ' + '==========\n')
#             result = recgonize(url, tag)
#             for i, ans in enumerate(result):
#                 if i != 0 and i != len(result) - 1: continue
#                 out.write(ans + '\n')
#         out.write('****************\n')
#
# recognizer.release()
# postagger.release()
# segmentor.release()  # 释放模型
# out.close()