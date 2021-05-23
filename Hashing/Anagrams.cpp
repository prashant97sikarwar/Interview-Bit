//Problem linK:- https://www.interviewbit.com/problems/anagrams/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &nums) {
    vector<vector<int>> result;
    unordered_map<string,vector<int>> ump;
    for(int i=0;i<nums.size();i++){
        string s = nums[i];
        sort(s.begin(),s.end());
        ump[s].push_back(i+1);
    }
    for(auto x : ump){
        result.push_back(x.second);
    }
    return result;
}
