//Problem Link:- https://www.interviewbit.com/problems/minimum-appends-for-palindrome/

#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    int n = A.length();
    int i = 0;
    int j = n-1;
    int cnt = 0;
    while(i<=j){
        if(A[i] == A[j]) {
            i++; j--;
        }
        else{
            if(j == n-1){
                cnt++;
                i++;
            }
            else{
                cnt += (n-1-j);
                j = n-1;
            }
        }
    }
    return cnt;
    
}