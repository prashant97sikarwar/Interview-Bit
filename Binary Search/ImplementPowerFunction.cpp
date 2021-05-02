//Problem Link:- https://www.interviewbit.com/problems/implement-power-function/

#include<bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d) {
    if (x == 0){
        return 0;
    }
    if (n == 0){
        return 1;
    }
    if (n == 1){
        return (x+d)%d;
    }
    long long base = x;
    long long res = 1;
    while (n > 0){
        if (n&1){
            res = (res*base)%d;
            n--;
        }
        else{
            base = (base*base)%d;
            n >>= 1;
        }
    }
    if (res < 0){
        res = (res+d)%d;
    }
    return res;
}

