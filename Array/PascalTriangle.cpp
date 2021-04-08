//Problem link:- https://www.interviewbit.com/problems/pascal-triangle/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >solve(int n) {
    if (n == 1)
        return {{1}};
    if (n == 2){
        return {{1},{1,1}};
    }
    vector<vector<int>> result;
    if (n > 2){
        result.push_back({1});
        result.push_back({1,1});
        vector<int> prev = result.back();
        for(int i=3;i<=n;i++){
            vector<int> temp(i,1);
            for(int j=1;j<i-1;j++){
                temp[j] = prev[j-1] + prev[j];
            }
            result.push_back(temp);
            prev = temp;
        }
    }
    return result;
}
