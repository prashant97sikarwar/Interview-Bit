//Problem Link:- https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int k) {
    if (k == 1)
        return {1,1};
    if (k == 0)
        return {1};
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    for(int i=2;i<=k;i++){
        vector<int> res(i+1,0);
        res[0] = 1;
        res[i] = 1;
        for(int j=1;j<i;j++){
            res[j] = temp[j-1] + temp[j];
        }
        temp = res;
    }
    return temp;
    
}
