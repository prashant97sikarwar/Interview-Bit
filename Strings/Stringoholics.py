# problem Link:- https://www.interviewbit.com/problems/stringoholics/

mod = 1000000007

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
    
def lcm(a,b):
    return a*b // gcd(a,b)

class Solution:
    # @param A : list of strings
    # @return an integer
    def solve(self, s):
        ans = []
        for i in range(len(s)):
            if  (s[i] == "a"*len(s[i]) or s[i] == "b"*len(s[i])):
                ans.append(1)
            else:
                j = 1
                while(j*(j+1)//2) % len(s[i]) != 0:
                    j += 1
                ans.append(j)
        res = ans[0]
        for i in range(1,len(ans)):
            res = lcm(res,ans[i])
        return res % mod
