//Problem Link:- https://www.interviewbit.com/problems/partitions/

#include<bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &arr) {
    int sm = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        sm += arr[i];
    }
    if (sm % 3 != 0)
        return 0;
    int c1 = 0;
    int part = sm / 3;
    int tot = 0;
    int res = 0;
    for(int i=0;i<n-1;i++){
        tot += arr[i];
        if (tot == 2*part){
            res += c1; 
        }
        if (tot == part){
            c1++;
        }
    }
    return res;
}
