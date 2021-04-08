//Problem Link:- https://www.interviewbit.com/problems/spiral-order-matrix-ii/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >generateMatrix(int n) {
    if (n == 1){
        return {{1}};
    }
    vector<vector<int>> mat(n,vector<int> (n,0));
    int rs = 0;
    int re = n-1;
    int cs = 0;
    int ce = n-1;
    int num = 1;
    while (rs <= re && cs <= ce){
        for(int i=rs;i<=re;i++){
            mat[cs][i] = num;
            num++;
        }
        cs++;
        for(int i=cs;i<=ce;i++){
            mat[i][re] = num;
            num++;
        }
        re--;
        if (cs <= ce){
            for(int i=re;i>=rs;i--){
                mat[ce][i] = num;
                num++;
            }
            ce--;
        }
        if (rs <= re){
            for(int i=ce;i>=cs;i--){
                mat[i][rs] = num;
                num++;
            }
            rs++;
        }
    }
    return mat;
}
