//Problem Link:- https://www.interviewbit.com/problems/rotate-matrix/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &mat) {
    int n = mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        int l = 0;
        int r = n-1;
        while (l <= r){
            swap(mat[i][l],mat[i][r]);
            l++;
            r--;
        }
    }
}
