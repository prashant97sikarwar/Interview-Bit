//Problem Link:- https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
    int res = 0;
    while (n > 0){
        n /= 5;
        res += n;
    }
    return res;
}
