//Problem Link:- https://www.interviewbit.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &dp,vector<vector<string>>& result,vector<string> temp,string s, int start){
    if (start == s.length()){
        result.push_back(temp);
    }
    for(int end=start;end<s.length();end++){
        if (s[start] == s[end] && (end-start+1 <= 2 || dp[start+1][end-1] == 1)){
            dp[start][end] = 1;
            temp.push_back(s.substr(start,end-start+1));
            helper(dp,result,temp,s,end+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> temp;
    int n = s.length();
    vector<vector<int>> dp(n,vector<int> (n,0));
    helper(dp,result,temp,s,0);
    return result;
}