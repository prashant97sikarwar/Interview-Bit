//Problem Link:- https://www.interviewbit.com/problems/3-sum-zero/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        long long sm = nums[i];
        int l = i+1,r = n-1;
        while (l < r){
            sm = (long long)nums[i] + (long long)nums[l] + (long long)nums[r];
            if (sm == 0){
                int f = nums[i];
                int s = nums[l];
                int t = nums[r];
                result.push_back({f,s,t});
                l++;
                r--;
                while(l < r && nums[l] == s && nums[r] == t){
                    l++;
                    r--;
                }
            }
            else if (sm > 0){
                r--;
            }
            else if (sm < 0){
                l++;
            }
        }
    }
    return result;
}
