//Problem Link:- https://www.interviewbit.com/problems/valid-number/

#include<bits/stdc++.h>
using namespace std;

int isNumber(const string s) {
    bool point = false;
    bool exp = false;
    bool numbefore = false;
    bool numafter = true;
    bool nump = true;
    int i = 0;
    while (i < s.length() && s[i] == ' '){
        i++;
    }
    int k = s.length()-1;
    while (k >= 0 && s[k] == ' '){
        k--;
    }
    for(i;i<=k;i++){
        if ('0' <= s[i] && s[i] <= '9'){
            numbefore =true;
            numafter = true;
            nump = true;
    }
    else if (s[i] == '.'){
        if (exp || point){
            return false;
        }
        point =  true;
        nump = false;
        numbefore = false;
    }
    else if (s[i] == 'e' || s[i] == 'E'){
        if (exp || !numbefore){
            return false;
        }
        exp = true;
        numafter = false;
        }
        else if (s[i] == '-' || s[i] == '+'){
            if(i != 0 && s[i-1] != 'e') {
                return false;
            }
        }
        else{
            return false;
        }
    }
    return numbefore && numafter && nump;
}
