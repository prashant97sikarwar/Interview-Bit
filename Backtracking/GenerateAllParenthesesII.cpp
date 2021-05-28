//Problem Link:- https://www.interviewbit.com/problems/generate-all-parentheses-ii/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<string>&result,string temp,int left,int right,int n){
    if (temp.length() == 2*n){
        result.push_back(temp);
        return;
    }
    if (left < n){
        helper(result,temp+'(',left+1,right,n);
    }
    if (right < left){
        helper(result,temp+')',left,right+1,n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper(result,"",0,0,n);
    return result;
}
