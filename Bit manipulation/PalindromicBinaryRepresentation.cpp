//Problem Link:- https://www.interviewbit.com/problems/palindromic-binary-representation/

#include<bits/stdc++.h>
using namespace std;

int convert(string s){
    int num = 0;
    for(int i=0;i<s.length();i++){
        num = 2*num + (s[i]-'0');
    }
    return num;
}

int solve(int n) {
    if (n == 1)
        return 1;
    n--;
    queue<string> pq;
    pq.push("11");
    while (!pq.empty()){
        string node = pq.front();
        n--;
        if (!n)
            return convert(node);
        pq.pop();
        int mid = node.length()/2;
        if (node.length()%2 == 0){
            string first = node;
            string sec = node;
            first.insert(mid,"0");
            sec.insert(mid,"1");
            pq.push(first);
            pq.push(sec);
        }
        else{
            string ch(1,node[mid]);
            string temp = node;
            temp.insert(mid,ch);
            pq.push(temp);
        }
    }
    return 0;
}
