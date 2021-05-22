//Problem Link:- https://www.interviewbit.com/problems/min-stack/

#include<bits/stdc++.h>
using namespace std;

vector<int> st,min_st;
int cur_min = INT_MAX;

void push(int x) {
    if (x < cur_min){
        min_st.push_back(cur_min);
        cur_min = x;
    }
    st.push_back(x);
}

void pop() {
    if (!st.empty()){
        if (st.back() == cur_min){
        cur_min = min_st.back();
        min_st.pop_back();
    }
    st.pop_back();
    }
    
}

int top() {
    return st.size() > 0 ? st.back() : -1;
}

int getMin() {
    return st.size() > 0 ? cur_min : -1;
}

