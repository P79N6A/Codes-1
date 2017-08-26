# -*- coding:utf-8 -*-
# [1, 2, 3]
# [1]
# [2, 1], [2]
# [3, 2, 1], [3, 2], [3]
# 都是往左补上大的
class Subset:
    # 返回二维[[],[],[]]
    def getSubsets(self, A, n):
        A.sort()
        ans = [[A[0]]]
        for i in range(1, n):
            temp = ans[:]
            for j in range(0, len(temp)):
                temp[j] = [A[i]] + temp[j]
            ans = temp + [[A[i]]] + ans
        return ans
    
    def getSubsetsMyAns(self, A, n):
        # write code here
        A.sort(reverse=True)
        ans = []
        for i in range(1, pow(2, n)):
            each = []
            for j in range(n):
                if i & (1 << j):
                    each.append(A[j])
            ans.append(each)
        ans.sort(reverse=True)
        return ans
        