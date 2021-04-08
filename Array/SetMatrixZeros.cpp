//problem link:- https://www.interviewbit.com/problems/set-matrix-zeros/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &mat) {
    int n = mat.size();
    int m = mat[0].size();
    bool flag = false;
    for(int i=0;i<m;i++){
        if (mat[0][i] == 0){
            flag = true;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if (mat[i][j] == 0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        if (mat[i][0] == 0){
            for(int j=0;j<m;j++){
                mat[i][j] = 0;
            }
        }
    }
    for(int i=0;i<m;i++){
        if (mat[0][i] == 0){
            for(int j=0;j<n;j++){
                mat[j][i] = 0;
            }
        }
    }
    if (flag){
        for(int i=0;i<m;i++){
            mat[0][i] = 0;
        }
    }
    
}
