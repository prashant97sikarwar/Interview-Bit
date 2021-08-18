# Problem Link:- https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution(object):
    def gcdOfStrings(self, str1, str2):
        n = len(str1)
        m = len(str2)
        if (n < m):
            n,m = m,n
            str1,str2 = str2,str1
        result = ""
        for i  in range(m):
            first = str2[0:i+1]
            t = len(first)
            if(n%t == 0 and m % t == 0):
                ln1 = n / t
                ln2 = m / t
                if (first*ln1 == str1 and first*ln2 == str2):
                    result = first
        return result