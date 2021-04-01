//Problem Link:- https://www.interviewbit.com/problems/reverse-bits/

#include<bits/stdc++.h>
using namespace std;

unsigned int reverse(unsigned int n) {
    unsigned int res = 0;
    for(int i=31;i>=0 && n > 0;i--){
        if (n&1){
            res |= (1 << i);
        }
        n >>= 1;
    }
    return res;
}
