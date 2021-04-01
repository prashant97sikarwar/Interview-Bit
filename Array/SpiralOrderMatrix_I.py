# Problem Link:- https://www.interviewbit.com/problems/spiral-order-matrix-i/

class Solution:
    def spiralOrder(self, A):
        xs, xe, ys, ye = 0, len(A)-1, 0, len(A[0])-1
        ans = []
        while (xs <= xe and ys <= ye):
            for i in range(ys,ye+1):
                ans.append(A[xs][i])
            xs += 1
            for i in range(xs,xe+1):
                ans.append(A[i][ye])
            ye -= 1
            if (xe >= xs): 
                for i in range(ye,ys-1,-1):
                    ans.append(A[xe][i])
                xe -= 1
            if (ys <= ye):
                for i in range(xe,xs-1,-1):
                    ans.append(A[i][ys])
                ys += 1
        return ans