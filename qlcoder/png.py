#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2017/12/2 19:10
# @Author  : Guo Ziyao
import struct
import binascii

def get_hex(data):
    result = list()
    for each in data:
        per = hex(ord(each)).replace('0x', '')
        if len(per) == 1:
            per = '0' + per
        result.append(per)
    return ''.join(result)


def check_png(data):
    pos = 0
    type_id = get_hex(data[: pos + 8])
    pos += 8
    if type_id != '89504E470D0A1A0A'.lower():
        print 'NOT A PNG FILE'
        return

    while pos < len(data):
        # Chunk长度
        length = struct.unpack('I', data[pos: pos + 4][:: -1])[0]
        print 'pos = ' + str(pos)
        pos += 4
        # Chunk标识
        tag = data[pos: pos + 4]
        print 'TAG: ' + tag
        pos += 4
        if pos + length > len(data):
            print 'ERROR LENGTH: ' + str(length)
            print 'REMAIN SIZE: ' + str(len(data) - pos)
            return False
        # 数据
        cdata = data[pos: pos + length]
        dcrc = binascii.crc32(tag + cdata)
        pos += length
        # crc
        crc = struct.unpack('I', data[pos: pos + 4][:: -1])[0]
        pos += 4

        print 'LEN: ' + str(length)
        print 'DATA CRC: ' + str(dcrc)
        print 'CRC: ' + str(crc)
        print '=================='
    return True


if __name__ == '__main__':
    print hex(8333)
    print hex(12441)
    print hex(4096)
    print int('0x60a6', 16)
    with open('1.png', 'rb') as f:
        p = 8333
        save = f.read()
        check_png(save)
        # for k in range(4):
        #     for i in range(16):
        #         for j in range(16):
        #             x = list(save)
        #             x[p + k] = chr(i * 16 + j)
        #             nx = ''.join(x)
        #             if check_png(nx):
        #                 print k, i, j
        #                 exit(0)
