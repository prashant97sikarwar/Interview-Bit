//Problem Link:- https://www.interviewbit.com/problems/counting-subarrays/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k) {
    int n = arr.size();
    int start = 0, end = 0,
        count = 0, sum = arr[0];
 
    while (start < n && end < n) {
        if (sum < k) {
            end++;
 
            if (end >= start)
                count += end - start;
                
            if (end < n)
                sum += arr[end];
        }
        else {
            sum -= arr[start];
            start++;
        }
    }
 
    return count;
}
