//Problem Link:- https://www.interviewbit.com/problems/redundant-braces/

#include<bits/stdc++.h>
using namespace std;

int braces(string s) {
    int n = s.length();
    stack<char> st;
    for(auto& ch : s){
        if (ch == ')'){
            char top = st.top();
            st.pop();
            bool flag = true;
            while (!st.empty() && top != '('){
                if (top == '+' || top == '-' || top == '*' || top == '/'){
                    flag = false;
                }
                top = st.top();
                st.pop();
            }
            if (flag == true){
                return 1;
            }
        }
        else{
            st.push(ch);
        }
    }
    return 0;
}
