//Problem Link:- https://www.interviewbit.com/old/problems/meeting-rooms/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &nums){
    vector<int> arr;
    vector<int> dep;
    for(int i=0;i<nums.size();i++){
        arr.push_back(nums[i][0]);
        dep.push_back(nums[i][1]);
    }
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int platform_needed = 1,result = 1,i = 1,j = 0;
    while (i < arr.size() && j < dep.size()){
        if (arr[i] < dep[j]){
            platform_needed++;
            i++;
        }
        else{
            platform_needed--;
            j++;
        }
        result = max(result,platform_needed);
    }
    return result;
}
