#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/1/1 16:26
# @Author  : Guo Ziyao
import cv2
import numpy as np

alph_binary = {
    "A": "110101001011",
    "B": "101101001011",
    "C": "110110100101",
    "D": "101011001011",
    "E": "110101100101",
    "F": "101101100101",
    "G": "101010011011",
    "H": "110101001101",
    "I": "101101001101",
    "J": "101011001101",
    "K": "110101010011",
    "L": "101101010011",
    "M": "110110101001",
    "N": "101011010011",
    "O": "110101101001",
    "P": "101101101001",
    "Q": "101010110011",
    "R": "110101011001",
    "S": "101101011001",
    "T": "101011011001",
    "U": "110010101011",
    "V": "100110101011",
    "W": "110011010101",
    "X": "100101101011",
    "Y": "110010110101",
    "Z": "100110110101",
    "0": "101001101101",
    "1": "110100101011",
    "2": "101100101011",
    "3": "110110010101",
    "4": "101001101011",
    "5": "110100110101",
    "6": "101100110101",
    "7": "101001011011",
    "8": "110100101101",
    "9": "101100101101",
    "+": "100101001001",
    "-": "100101011011",
    "*": "100101101101",
    "/": "100100101001",
    "%": "101001001001",
    "$": "100100100101",
    ".": "110010101101",
    " ": "100110101101",
}


def generate_code(code):
    # 首尾一定是*
    # 所有字符后面都跟单位宽度白条
    white = (255, 255, 255)
    width = 2
    height = 60
    code = '*' + code + '*'
    image = np.zeros((height, width * (len(code) * 12 + (len(code))), 3), dtype=np.uint8)
    index = 0
    for each in code:
        binary = alph_binary[each]
        for bit in binary:
            if bit == '0':
                cv2.rectangle(image, (index, 0), (index + width - 1, height), white, -1)
            index += width
        cv2.rectangle(image, (index, 0), (index + width - 1, height), white, -1)
        index += width
    cv2.imwrite('tmp.jpg', image)


if __name__ == '__main__':
    generate_code("082808416")