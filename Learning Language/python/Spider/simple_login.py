#encoding:utf-8
import re
import urllib
import urllib2

con = urllib2.urlopen('http://123.206.34.196:86/')
content = con.read()
regular = {
    'viewstate': re.compile('id="__VIEWSTATE" value="(.+)" />'),
    'eventvalidation': re.compile('id="__EVENTVALIDATION" value="(.+)" />')
}
VIEWSTATE = regular['viewstate'].findall(content)[0]
EVENTVALIDATION = regular['eventvalidation'].findall(content)[0]

# print VIEWSTATE
# print EVENTVALIDATION

values = {
"GradeList":"软件2014级",
"RoomNameList":"梅六305",
"RealUmpiresText": "4",
"OtherInformation":"都齐了",
"ButtonSummit":"提交",
"__EVENTTARGET": "",
"__EVENTARGUMENT": "",
"__LASTFOCUS": "",
"__VIEWSTATE": VIEWSTATE,
"__EVENTVALIDATION": EVENTVALIDATION
}

data = urllib.urlencode(values)

url = "http://123.206.34.196:86/"

user_agent = 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.95 Mobile Safari/537.36'
headers = {'User-Agent' : user_agent}

req = urllib2.Request(url, data, headers)
response = urllib2.urlopen(req)

print response.read()

# values={}
# values['username'] = "20141792"
# values['password']="xxxxxx"
# data = urllib.urlencode(values) 
# url = "http://202.202.1.176:8080/_data/index_login.aspx"
# geturl = url + "?" + data
# request = urllib2.Request(geturl)
# response = urllib2.urlopen(request)