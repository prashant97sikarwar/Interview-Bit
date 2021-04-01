//Problem Link:- https://www.interviewbit.com/problems/number-of-1-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int numSetBits(unsigned int n) {
        int ans = 0;
        while (n > 0){
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
};
