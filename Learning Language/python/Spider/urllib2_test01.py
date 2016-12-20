import urllib2

print "hello"

response = urllib2.urlopen('https://www.baidu.com')
html = response.read()

print html