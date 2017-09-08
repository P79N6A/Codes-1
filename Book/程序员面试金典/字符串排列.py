# -*- coding:utf-8 -*-
class Permutation:
    def swap(self, li, i, j):
        (li[i], li[j]) = (li[j], li[i])

    def gen(self, A, pos, ans):
        if pos == len(A):
            ans.append(''.join(A))
            return
        for i in range(pos, len(A)):
            self.swap(A, pos, i)
            self.gen(A, pos + 1, ans)
            self.swap(A, pos, i)

    def getPermutation(self, A):
        ans = []
        A = list(A)
        A.sort()
        self.gen(A, 0, ans)
        ans.sort(reverse=True)
        return ans