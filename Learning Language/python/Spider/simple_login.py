import urllib
import urllib2

values = {"username" : "20141792", "password" : "xxxxxx"}
data = urllib.urlencode(values)

url = "http://202.202.1.176:8080/_data/index_login.aspx"
req = urllib2.Request(url, data)
response = urllib2.urlopen(req)

print response.read()

values={}
values['username'] = "20141792"
values['password']="xxxxxx"
data = urllib.urlencode(values) 
url = "http://202.202.1.176:8080/_data/index_login.aspx"
geturl = url + "?" + data
request = urllib2.Request(geturl)
response = urllib2.urlopen(request)