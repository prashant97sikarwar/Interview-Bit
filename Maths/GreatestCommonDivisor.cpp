//Problem Link:- https://www.interviewbit.com/problems/greatest-common-divisor/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0){
        return a;
    }
    return gcd(b,a%b);
}
