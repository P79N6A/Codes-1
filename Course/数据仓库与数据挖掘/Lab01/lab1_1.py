# -*- coding: utf-8 -*-
"""
Created on Mon May 15 19:17:48 2017

@author: GooZy
"""

import urllib
import re
import csv

req = urllib.urlopen('http://www.pagesjaunes.mg/entreprise/rianando/')
raw_data = req.read()

company = re.findall('"og:title".*content="(.*)"', raw_data)
category = re.findall('<h1>' + company[0].upper() + '[\s]*<span>(.*)</span>', raw_data)
address = re.findall('class="fa fa-home"[\s\S]*?<span>(.*)</span>', raw_data)
phone = re.findall('class="fa fa-phone"></i>[\s\S]*?<span>([\s\S]*?)</span>', raw_data)
email = re.findall('class="fa fa-envelope"></i>[\s\S]*?<a href=[\'"]mailto:(.*?)[\'"]', raw_data)

# process two or more phone number
new_phone = phone[0].replace('<br>', ',').strip()
if new_phone[-1] == ',':
    new_phone = new_phone[0:-1]

print 'Company,', company[0]
print 'Category,', category[0]
print 'Address,', address[0]
print 'Phone,', new_phone
print 'Email,', email[0]

csvfile = file('Lab1_1.csv', 'wb')
writer = csv.writer(csvfile)
writer.writerow(['Company', 'Category', 'Address', 'Phone', 'Email'])

data = [
    (company[0], category[0], address[0], new_phone, email[0])
]
writer.writerows(data)

csvfile.close()