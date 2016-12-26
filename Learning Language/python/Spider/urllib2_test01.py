import urllib2

print "hello"

response = urllib2.urlopen('http://cuiqingcai.com/942.html')
html = response.read()

print html