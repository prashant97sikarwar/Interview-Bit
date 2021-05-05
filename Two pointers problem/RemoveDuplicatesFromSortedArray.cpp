//Problem Link:- https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    int cur = 1;
    for(int i=0;i<n-1;i++){
        if (nums[i] == nums[i+1]){
            continue;
        }
        else{
            nums[cur] = nums[i+1];
            cur++;
        }
    }
    while (cur < nums.size()){
        nums.pop_back();
    }
    return nums.size();
}
