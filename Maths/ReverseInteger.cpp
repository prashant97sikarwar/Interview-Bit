//Problem Link:- https://www.interviewbit.com/problems/reverse-integer/

#include<bits/stdc++.h>
using namespace std;

int reverse(int num) {
    int sign;
    sign = (num >= 0) ? 1 : -1;
    long long int rev = 0;
    num = abs(num);
    while (num > 0){
        int rem = num % 10;
        rev = 10 * rev + rem;
        if (sign*rev > INT_MAX || sign*rev < INT_MIN){
            return 0;
        }
        num /= 10;
    }
    rev = sign*rev;
    if (rev > INT_MAX || rev < INT_MIN){
        return 0;
    }
    return rev;
}
