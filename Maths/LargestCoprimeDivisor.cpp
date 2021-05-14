//Problem Link:- https://www.interviewbit.com/problems/largest-coprime-divisor/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if (b == 0){
        return a;
    }
    return gcd(b,a%b);
}

int cpFact(int A, int B) {
    while (gcd(A,B) != 1){
        A = A / gcd(A,B);
    }
    return A;
}
