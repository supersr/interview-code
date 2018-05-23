#使用快排的思想找出最小的k个数
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        c = []
        if tinput == None:
            return 
        if k == 0:
            return c 
        length = len(tinput)
        i = -1
        j = 0
        b = tinput[-1]
        print tinput
        while j < length - 1:
            if tinput[j] < b:
                i += 1
                tinput[i],tinput[j] = tinput[j],tinput[i]
            j += 1
        tinput[i + 1],tinput[-1] = tinput[-1],tinput[i + 1]
        print tinput,k
        if i + 1 == k:
            return tinput[0: i + 2]
        elif i + 1 > k:
            return self.GetLeastNumbers_Solution(tinput[0: i+1], k)
        else:
            return tinput[0: i + 2] + self.GetLeastNumbers_Solution(tinput[i + 2:], k - i - 2)
if __name__ == '__main__':
	a = [4,5,1,6,2,7,3,8]
	k = 4
	print Solution().GetLeastNumbers_Solution(a,k)