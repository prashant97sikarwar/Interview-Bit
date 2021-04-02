//Problem Link:- https://www.interviewbit.com/problems/add-one-to-number/

#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    int carry = 0;
    if (n == 1){
        if (A[0] == 9){
            return {1,0};
        }
        else{
            return {A[0]+1};
        }
    }
    int sm = (A[n-1] + 1)%10;
    carry = (A[n-1]+1) / 10;
    A[n-1] = sm;
    for(int i=n-2;i>=0;i--){
        sm = (A[i] + carry)%10;
        carry = (A[i] + carry) / 10;
        A[i] = sm;
    }
    if (carry == 1){
        A.insert(A.begin(),1);
        return A;
    }
    else{
        int idx;
        for(int i=0;i<A.size();i++){
            if (A[i] != 0){
                idx = i;
                break;
            }
        }
        vector<int>res(A.begin() + idx,A.end());
        return res;
    }
    
}
