//Problem Link:- https://www.interviewbit.com/problems/max-product-subarray/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(const vector<int> &nums){
    int n = nums.size();
    int cur_max = nums[0];
    int cur_min = nums[0];
    int res = nums[0];
    for(int i=1;i<n;i++){
        int temp = cur_max;
        cur_max = max(cur_max*nums[i], max(nums[i], nums[i]*cur_min));
        cur_min = min(cur_min*nums[i], min(nums[i], nums[i]*temp));
        res = max(res, cur_max);
    }
    return res;
}
