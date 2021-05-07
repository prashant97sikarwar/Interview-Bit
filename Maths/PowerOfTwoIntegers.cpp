//Problem Link:- https://www.interviewbit.com/problems/power-of-two-integers/

#include<bits/stdc++.h>
using namespace std;

int isPower(int n) {
    if (n == 1){
        return 1;
    }
    for(int i=2;i*i<=n;i++){
        double val = log(n) / log(i);
        if (val - (int)val < 0.00000001){
            return true;
        }
    }
    return false;
}
