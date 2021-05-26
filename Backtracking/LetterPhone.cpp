//Problem Link:- https://www.interviewbit.com/problems/letter-phone/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<string> &result,vector<string> &keypad,string digits, string temp,int idx){
    if (idx >= digits.length()){
        result.push_back(temp);
        return;
    }
    string letters = keypad[digits[idx]-'0'];
    for(int i=0;i<letters.length();i++){
        temp.push_back(letters[i]);
        helper(result,keypad,digits,temp,idx+1);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.length() == 0){
        return {};
    }
    vector<string> keypad = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string temp;
    helper(result,keypad,digits,temp,0);
    return result;
}
