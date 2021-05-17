//Problem Link:- https://www.interviewbit.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>
using namespace std;

int helper(string &s, int l, int r){
    while (l >= 0 && r < s.length() && s[l] == s[r]){
        l--;
        r++;
    }
    return r-l-1;
}

string longestPalindrome(string s) {
    int res = 0;
    int st = 0;
    for(int i=0;i<s.length();i++){
        int l1 = helper(s,i,i);
        int l2 = helper(s,i,i+1);
        int len = max(l1,l2);
        if (len > res){
            res = len;
            st = i - (len-1)/2;
        }
    }
    return s.substr(st,res);
}
