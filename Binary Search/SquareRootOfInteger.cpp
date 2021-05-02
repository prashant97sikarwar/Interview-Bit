//Problem Link;- https://www.interviewbit.com/problems/square-root-of-integer/

#include<bits/stdc++.h>
using namespace std;

int sqrt(int num) {
    if (num == 0){
        return 0;
    }
    if (num == 1){
        return 1;
    }
    int l = 1;
    int r = num;
    while (l <= r){
        int mid = l + (r-l)/2;
        if (mid == num/mid){
            return mid;
        }
        else if (mid < num/mid){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return r;
}
