//Problem Link:- https://www.interviewbit.com/problems/implement-strstr/

#include<bits/stdc++.h>
using namespace std;

int strStr(const string A, const string B) {
    int n = A.length(),m = B.length(),i = 0,j = 0;
    int idx = -1;
    if (m > n){
        return -1;
    }
    while (i < n){
        if (j >= m){
            return idx;
        }
        if (A[i] == B[j]){
            if (idx == -1){
                idx = i;
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        else{
            i = (idx == -1) ? i+1 : idx+1;
            j = 0;
            idx = -1;
        }
    }
    return (j >= m) ? idx : -1;
}
