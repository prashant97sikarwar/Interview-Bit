#Problem link:- https://www.interviewbit.com/problems/anti-diagonals/

class Solution:
    def diagonal(self, mat):
        n = len(mat)
        result = []
        for i in range(n):
            lst = []
            x = 0
            while (x >= 0 and i >= 0 and x < n and i < n):
                lst.append(mat[x][i])
                x+=1
                i-=1
            result.append(lst)
        for i in range(1,n):
            j = n-1
            lst = []
            while(i >= 0 and j >= 0 and i < n and j < n):
                lst.append(mat[i][j])
                i+=1
                j-=1
            result.append(lst);
        return result