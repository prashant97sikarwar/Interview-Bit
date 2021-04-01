# Problem Link:- https://www.interviewbit.com/problems/max-non-negative-subarray/

class Solution:
    def maxset(self, A):
        i = 0
        maxi = -1
        index = 0
        length=0
        a = []
        
        while i < len(A):
            while i < len(A) and A[i] < 0:
                i+=1
            l = []
            index = i
            while i < len(A) and A[i] >= 0:   
                l.append(A[i])
                i+=1
            
            if (sum(l) > maxi):
                a = l
                maxi = sum(l)
                length=len(l)
                  
            if (sum(l)==maxi) and (len(l)>length):
                a = l
                maxi = sum(l)
                length=len(l)
          
        return a