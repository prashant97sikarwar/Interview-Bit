//Problem Link:- https://www.interviewbit.com/problems/excel-column-title/

#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int num) {
    string res;
    while (num > 0){
        int rem = num%26;
        if (rem == 0){
            res.push_back('Z');
            num = (num / 26) - 1;
        }
        else{
            res.push_back(rem-1+'A');
            num /= 26;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
