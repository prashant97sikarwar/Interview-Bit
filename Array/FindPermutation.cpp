//Problem Link:- https://www.interviewbit.com/problems/find-permutation/

#include<bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int B) {
    int cur_sm = 1;
    int cur_lar = B;
    vector<int> result;
    for(int i=0;i<A.size();i++){
        if (A[i] == 'I'){
            result.push_back(cur_sm);
            cur_sm++;
        }
        else{
            result.push_back(cur_lar);
            cur_lar--;
        }
    }
    if (A[A.size()-1] == 'I'){
        result.push_back(cur_sm);
    }
    else{
        result.push_back(cur_lar);
    }
    return result;
}
