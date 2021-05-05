//Problem Link:- https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2){
        return n;
    }
    int i=0,count=0;
    while (i < n){
        if (i < n-2 && nums[i] == nums[i+1] && nums[i] == nums[i+2]){
            i++;
            continue;
        }
        else{
            nums[count++] = nums[i++];
        }
    }
    return count;
}
