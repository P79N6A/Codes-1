# -*- coding:utf-8 -*-
class MagicIndex:
    def findMagicIndex(self, A, n):
        l = 0
        r = n - 1
        while l <= r:
            mid = (l + r) / 2
            if A[mid] == mid:
                return True
            elif A[mid] > mid:
                r = mid - 1
            else:
                l = mid + 1
        return False
    
    def another_answer(self, A, n):
        """
        我也是服气啊，太有道理了，我怎么没发现，23333
        """
        return A[0] == 0