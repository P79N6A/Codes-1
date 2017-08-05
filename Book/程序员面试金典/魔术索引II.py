# -*- coding:utf-8 -*-
class MagicIndex:
    def findMagicIndex(self, A, n):
        s = 0
        while A[s] != s:
            s = A[s]
            if s >= n:
                return False
        return True