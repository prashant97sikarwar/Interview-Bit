//problem Link:- https://www.interviewbit.com/problems/single-number/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
    int res = 0;
    for(int i=0;i<A.size();i++){
        res ^= A[i];   
    }
    return res;
}
