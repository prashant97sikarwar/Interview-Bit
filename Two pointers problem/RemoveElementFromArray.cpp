//Problem Link:- https://www.interviewbit.com/problems/remove-element-from-array/

#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int k) {
    int n = nums.size();
    int count = 0;
    for(int i=0;i<n;i++){
        if (nums[i] != k){
            nums[count++] = nums[i];
        }
        else{
            continue;
        }
    }
    return count;
}
