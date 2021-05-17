//Problem Link:- https://www.interviewbit.com/problems/minimum-parantheses/

#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int cnt = 0;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else if (st.empty() && s[i] == ')'){
            cnt++;
        }
        else if (!st.empty() && s[i] == ')'){
            st.pop();
        }
    }
    return cnt + st.size();
}
