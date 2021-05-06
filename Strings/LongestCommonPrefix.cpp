//Problem Link;- https://www.interviewbit.com/problems/longest-common-prefix/

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &nums) {
    int n = nums.size();
    string ans;
    int idx = 0;
    while(1){
        char temp = nums[0][idx];
        for(int i=0;i<n;i++){
            if (idx >= nums[i].length()){
                return ans;
            }
            if (nums[i][idx] != temp){
                return ans;
            }
        }
        ans.push_back(nums[0][idx]);
        idx++;
        if (idx >= nums[0].length()){
            break;
        }
    }
    return ans;
}
