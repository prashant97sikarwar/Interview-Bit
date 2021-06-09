//Problem Link:- https://www.interviewbit.com/problems/highest-product/

#include<bits/stdc++.h>
using namespace std;

int maxp3(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int op1 = nums[0]*nums[1]*nums[n-1];
    int op2 = nums[n-1]*nums[n-2]*nums[n-3];
    return max(op1,op2);
}
