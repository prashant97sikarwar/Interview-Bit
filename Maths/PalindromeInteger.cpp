//Problem Link:- https://www.interviewbit.com/problems/palindrome-integer/

#include<bits/stdc++.h>
using namespace std;

int isPalindrome(int n) {
    if (n == 0){
        return true;
    }
    if (n < 0){
        return false;
    }
    int rev = 0;
    int num = n;
    while (num > 0){
        int rem = num % 10;
        rev = rev*10 + rem;
        num /= 10;
    }
    if (rev == n){
        return true;
    }
    return false;
}
