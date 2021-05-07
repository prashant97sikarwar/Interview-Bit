//Problem Link:- https://www.interviewbit.com/courses/programming/topics/hashing/

#include<bits/stdc++.h>
using namespace std;

int colorful(int n) {
    vector<int> arr;
    unordered_set<int> s;
    while (n){
        int rem = n % 10;
        arr.push_back(rem);
        n /= 10;
        if (s.find(rem) != s.end()){
            return 0;
        }
        s.insert(rem);
    }
    for(int i=0;i<arr.size();i++){
        int mul = arr[i];
        for(int j=i+1;j<arr.size();j++){
            mul *= arr[j];
            if (s.find(mul) != s.end()){
                return 0;
            }
            s.insert(mul);
        }
    }
    return 1;
}
