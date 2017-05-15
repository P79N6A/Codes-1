# -*- coding: utf-8 -*-
"""
Created on Mon May 15 20:50:48 2017

@author: GooZy
"""
# http://www.pagesjaunes.mg/page/page/[1,59]/?search=advanced&icateg=2

import urllib
import re
import csv
import threading
import os

url_head = 'http://www.pagesjaunes.mg/page/page/'
url_tail = '/?search=advanced&icateg=2'

def process_page(page_num):
    
    filename = 'result/Lab12_' + str(page_num) + '.csv'
    # if extracted, just pass it
    if os.path.exists(filename) and os.path.getsize(filename) > 2000:
        return
    
    req = urllib.urlopen(url_head + str(page_num) + url_tail)
    raw_data = req.read()
    links = re.findall('<a href=[\'"](.*?)[\'"] class="btn btn-default">', raw_data)
    
    csvfile = file(filename, 'wb')
    writer = csv.writer(csvfile)
    writer.writerow(['Company', 'Category', 'Address', 'Phone', 'Email'])
    
    for link in links:
        link_req = urllib.urlopen(link)
        data = link_req.read()
        
        company = re.findall('"og:title".*content="(.*)"', data)
        
        # special judge
        if len(company) == 0:
            company.append(' ')
            
        category = re.findall('<h1>' + company[0].upper() + '[\s]*<span>(.*)</span>', data)
        address = re.findall('class="fa fa-home"[\s\S]*?<span>(.*)</span>', data)
        phone = re.findall('class="fa fa-phone"></i>[\s\S]*?<span>([\s\S]*?)</span>', data)
        email = re.findall('class="fa fa-envelope"></i>[\s\S]*?<a href=[\'"]mailto:(.*?)[\'"]', data)
        
        # special judge
        if len(category) == 0:
            category.append(' ')
        if len(address) == 0:
            address.append(' ')
        if len(phone) == 0:
            phone.append(' ')
        if len(email) == 0:
            email.append(' ')
        
        # process two or more phone number
        new_phone = phone[0].replace('<br>', ',')
        if new_phone[-1] == ',':
            new_phone = new_phone[0:-1]
        
        final_data = [
            (company[0], category[0], address[0], new_phone, email[0])
        ]
        writer.writerows(final_data)
    
    csvfile.close()


# Use multithreading

threads = []
for page_num in range(1, 60):
    threads.append(threading.Thread(target=process_page, args=(page_num, )))

for t in threads:
    t.start()





