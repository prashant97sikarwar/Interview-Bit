//Problem Link:- https://www.interviewbit.com/problems/length-of-last-word/

#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
    int n = A.length();
    int res = 0;
    int p;
    for(int i=n-1;i>=0;i--){
        if (A[i] != ' '){
            p = i;
            break;
        }
    }
    for(int i=p;i>=0;i--){
        if (isalpha(A[i])){
            res++;
        }
        else{
            break;
        }
    }
    return res;
}
