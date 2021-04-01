//problem Link:- https://www.interviewbit.com/problems/single-number-ii/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
    int res = 0;
    for(int i=0;i<=31;i++){
        int mask = (1 << i);
        int cnt = 0;
        for(int idx=0;idx<A.size();idx++){
            if (A[idx] & mask){
                cnt++;
            }
        }
        if (cnt % 3 != 0){
            res |= (1 << i);
        }
    }
    return res;
}
