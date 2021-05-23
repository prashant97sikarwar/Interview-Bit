//Problem Link;- https://www.interviewbit.com/problems/4-sum/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    if (n <= 3){
        return result;
    }
    for(int i=0;i<n-3;i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        if (nums[i]*4 > target){
            break;
        }
        for(int j=i+1;j<n-2;j++){
            if (j > i+1 && nums[j] == nums[j-1]){
                continue;
            }
            if (nums[j]*3 > target - nums[i]){
                break;
            }
            int l = j+1;
            int r = n-1;
            while (l < r){
                int sm = nums[i] + nums[j] + nums[l] + nums[r];
                if (sm == target){
                    result.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while (l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    while (l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (sm < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
    }
    return result;
}
