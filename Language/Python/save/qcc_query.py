#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time   : 2018/11/22 18:44
# @Author : GUO Ziyao
# @Desc   : Plz describe your script

import csv
import logging

from metis_common.util.qcc_util import get_details_by_name, main_province_dict
from metis_common.common.producers import kafka_qcc_cache_producer


def run(*args):
    limit = 1
    lno = 0
    try:
        with open('result.csv', 'w') as fw:
            w = csv.DictWriter(fw, fieldnames=['customer_id', 'customer_name', 'company_name', 'address', 'province', 'credit_code',
                                               'reg_num', 'org_no', 'operating_start', 'operating_end'])
            w.writeheader()
            with open('/home/guoziyao/repos/metis_task/metis_task/task/t2.csv', 'rU') as f:
                r = csv.DictReader(f, fieldnames=['customer_name', 'customer_id'])
                for each in r:
                    lno += 1
                    if lno <= limit:
                        continue
                    company_name = each['customer_name'].decode('utf8')

                    result = get_details_by_name(company_name)
                    data = dict(customer_name=company_name, customer_id=each['customer_id'])
                    if result.get('Status', '') == '200':
                        result = result.get('Result')
                        data['company_name'] = result['Name']  # 公司名称
                        data['province'] = main_province_dict.get(result['Province'], '')
                        data['address'] = result['Address']
                        data['reg_num'] = result['No']  # 注册号
                        data['credit_code'] = result['CreditCode']  # 社会统一信用代码
                        data['org_no'] = result['OrgNo']  # 组织机构代码
                        data['operating_start'] = result.get('TermStart', '').split('T')[0] if result.get('TermStart',
                                                                                                              '') else ''  # 营业期限自
                        data['operating_end'] = result.get('TeamEnd', '').split('T')[0] if result.get('TeamEnd',
                                                                                                          '') else ''  # 营业期限至
                        kafka_qcc_cache_producer.send_msg(result)
                    for k, v in data.items():
                        if isinstance(v, unicode):
                            data[k] = v.encode('utf8')
                    w.writerow(data)
    finally:
        logging.info('total: %s' % lno)
