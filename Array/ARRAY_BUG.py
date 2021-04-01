# Problem Link:- https://www.interviewbit.com/problems/arraybug/

class Solution:
    def rotateArray(self, a, b):
        ret = []
        for i in range(b,len(a)):
            ret.append(a[i])
        for i in range(b):
            ret.append(a[i])
        return ret