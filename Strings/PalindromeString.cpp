//Problem link:- https://www.interviewbit.com/problems/palindrome-string/

#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s) {
    string str;
    for(int i=0;i<s.length();i++){
        if (isalnum(s[i])){
            str.push_back(s[i]);
        }
    }
    if (str.length() <= 1){
        return 1;
    }
    const int x = 32;
    int l = 0;
    int r = str.length()-1;
    while (l < r){
        if ((str[l] == str[r]) || (str[l] | x) == (str[r] | x)){
            l++;
            r--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
