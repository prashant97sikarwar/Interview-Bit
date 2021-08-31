//Problem Link:- https://www.interviewbit.com/old/problems/sum-of-fibonacci-numbers/

#include<bits/stdc++.h>
using namespace std;

void calculateFibo(vector<int>& fiboTerms, int k){
    fiboTerms.push_back(0);
    fiboTerms.push_back(1);
    fiboTerms.push_back(1);
    int i = 3;
    while (true){
        int newTerm = fiboTerms[i-1] + fiboTerms[i-2];
        if (newTerm > k){
            break;
        }
        fiboTerms.push_back(newTerm);
        i++;
    }
}

int fibsum(int k) {
    vector<int> fiboTerms;
    calculateFibo(fiboTerms,k);
    int j = fiboTerms.size()-1;
    int result = 0;
    while (k > 0){
        result += (k/fiboTerms[j]);
        k = k % fiboTerms[j];
        j--;
    }
    return result;
}
