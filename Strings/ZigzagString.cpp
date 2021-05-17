//Problem Link:-https://www.interviewbit.com/problems/zigzag-string/

#include<bits/stdc++.h>
using namespace std;

string convert(string A, int B) {
    string res;
    int n = A.size();
    int i = 0;
    int x = 0;
    if(B == 1)
    return A;
    if(n<=1)
    return A;
    for(int j = B;j>0;j--)
    {
        while(i<n)
        {
            if(j != 1)
            {
                res += A[i];
                i += 2*j - 2;
            }
            if(j != B)
            {
                if(i<n)
                res += A[i];
                i += 2*(B-j+1) - 2;
            }
        }
        i = ++x;
    }
    return res;
}