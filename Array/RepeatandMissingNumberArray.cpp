//PRoblem link:- https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    int a,b;
    int n = A.size();
    vector<int> freq(n+1,0);
    for(int i=0;i<n;i++){
        freq[A[i]]++;
    }
    for(int i=1;i<=n;i++){
        if (freq[i] == 0){
            b = i;
        }
        else if (freq[i] == 2){
            a = i;
        }
    }
    return {a,b};
}
