#encoding:UTF-8
import urllib.request
import sys

def getHtml(url):
    html = urllib.request.urlopen(url).read() #二进制字节形式
    return html.decode('UTF-8')

print("请输入需要爬取的网址:");
urll = input()
html = getHtml(urll)

fh = open('test.html','w', encoding='utf-8')
fh.write(html)
fh.close()

print("ok!")
