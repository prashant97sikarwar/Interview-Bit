//Problem Link:- https://www.interviewbit.com/problems/sort-by-color/

#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums) {
    int l = 0;
    int r = nums.size()-1;
    int i = 0;
    while (i <= r){
        if (nums[i] == 0){
            swap(nums[i],nums[l]);
            l++;
            i++;
        }
        else if (nums[i] == 1){
            i++;
        }
        else if (nums[i] == 2){
            swap(nums[i],nums[r]);
            r--;
        }
    }
    
}
