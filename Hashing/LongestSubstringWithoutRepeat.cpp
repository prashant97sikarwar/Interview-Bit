//Problem Link:- https://www.interviewbit.com/problems/longest-substring-without-repeat/

#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> &freq){
    for(int i=0;i<128;i++){
        if (freq[i] > 1){
            return true;
        }
    }
    return false;
}

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    vector<int> freq(128,0);
    int left = 0,res = 0;
    for(int i=0;i<n;i++){
        freq[s[i]-' ']++;
        while (left < n && helper(freq)){
            freq[s[left]-' ']--;
            left++;
        }
        res = max(res,i-left+1);
    }
    return res;
}
