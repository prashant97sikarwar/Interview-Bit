//problem Link:- https://www.interviewbit.com/problems/matrix-search/

#include<bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &mat, int B) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
        if (mat[i][m-1] >= B){
            auto it = lower_bound(mat[i].begin(),mat[i].end(),B);
            if (*it == B){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    return 0;
}

