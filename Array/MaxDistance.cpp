//Problem Link:- https://www.interviewbit.com/problems/max-distance/

#include<bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &arr){
    int n = arr.size();
    if (n == 1){
        return 0;
    }
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i=1;i<n;i++){
        left[i] = min(arr[i],left[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        right[i] = max(arr[i],right[i+1]);
    }
    int diff = INT_MIN;
    int i = 0,j=0;
    while (i < n && j < n){
        if (left[i] <= right[j]){
            diff = max(diff,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return diff;
}
