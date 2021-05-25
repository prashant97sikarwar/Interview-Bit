//Problem Link:- https://www.interviewbit.com/problems/subset/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > subsets(vector<int> &nums) {
    int ln = nums.size();
    vector<vector<int>> result;
    int n = 1 << ln;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<ln;j++){
            int mask = (1 << j);
            if (mask & i){
                temp.push_back(nums[j]);
            }
        }
        sort(temp.begin(),temp.end());
        result.push_back(temp);
    }
    sort(result.begin(),result.end());
    return result;
}
