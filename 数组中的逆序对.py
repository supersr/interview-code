# -*- coding:utf-8 -*-
#数组中的逆序对，剑指Offer运行并没成功，但自己测试正确
class Solution:
    def InversePairs(self, data):
        # write code here
        length = len(data)
        if data == None:
            return 0
        a = [i for i in data]
        count = self.InversePairsCore(data,a,0,length - 1) % 1000000007
        return count
    def InversePairsCore(self,data,a,start,end):
        if start == end:
            a[start] = data[start]
            return 0
        length = (end - start) / 2
        left = self.InversePairsCore(a,data,start,start + length)
        right = self.InversePairsCore(a,data,start + length + 1, end)
        i = start + length
        j = end
        count = 0
        indexCopy = end
        while i >= start and j >= (start + length +1):
            if data[i] > data[j]:
                a[indexCopy] = data[i]
                indexCopy -= 1
                count += j - start - length
                i -= 1
            else:
                a[indexCopy] = data[j]
                indexCopy -= 1
                j -= 1
        while i >= start:
            a[indexCopy] = data[i]
            indexCopy -= 1
            i -= 1
        while j >= (start + length + 1):
            a[indexCopy] = data[j]
            j -= 1
            indexCopy -= 1
        return left + right + count
