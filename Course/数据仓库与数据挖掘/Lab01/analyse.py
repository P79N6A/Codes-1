# -*- coding: utf-8 -*-
"""
Created on Mon May 15 21:58:40 2017

@author: GooZy
"""

import csv

email_num = 0
company_num = 0
email_dic = dict()

for page_num in range(1, 60):
    csv_reader = csv.reader(file('result/Lab12_' + str(page_num) + '.csv', 'rb'))
    # Pass the first row
    pas = True
    for line in csv_reader:
        if pas:
            pas = False
            continue
        if line[0] != ' ':
            company_num += 1
        if line[4] != ' ':
            email_num += 1
            email_dic[line[4]] = 1

print 'Total email address:', email_num
print 'Total company names:', company_num
print 'Total unique email address:', len(email_dic)