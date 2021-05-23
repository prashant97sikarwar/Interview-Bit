//Problem Link:- https://www.interviewbit.com/problems/window-string/

#include<bits/stdc++.h>
using namespace std;

string minWindow(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    
    int left = 0;
    unordered_map<char,int> ump1, ump2;
    int count = 0;
    int res = INT_MAX,st = 0;
    for(int i=0;i<m;i++){
        ump2[str2[i]]++;
    }
    
    for(int i=0;i<n;i++){
        char c = str1[i];
        ump1[c]++;
        if (ump2[c] >= ump1[c] && ump2[c] > 0){
            count++;
        }
        if (count == m){
            while (left < i && ump2[str1[left]] < ump1[str1[left]] || ump2[str1[left]] == 0){
                if(ump2[str1[left]] < ump1[str1[left]]) {
                    ump1[str1[left]]--;
                }
                left++;
            }
            if (res > i-left+1){
                res = i-left+1;
                st = left;
            }
        }
    }
    if (res == INT_MAX){
        return "";
    }
    return str1.substr(st,res);
}
