//problem Link:- https://www.interviewbit.com/problems/find-nth-fibonacci/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void multiply(vector<vector<int>> &A,vector<vector<int>> &B){
    vector<vector<long long>> result(2,vector<long long> (2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                long long sm = (1LL*A[i][k] * B[k][j])%MOD;
                result[i][j] += sm;
                result[i][j] %= MOD;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j] = result[i][j];
        }
    }
}

int getfib(int a,int b,int n){
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 2;
    }
    vector<vector<int>> identity(2,vector<int> (2,0));
    for(int i=0;i<2;i++){
        identity[i][i] = 1;
    }
    vector<vector<int>> mat(2,vector<int> (2,0));
    mat[0][1] = 1, mat[1][0] = 1,mat[1][1] = 1;
    n = n-1;
    while (n > 0){
        if (n&1){
            multiply(identity,mat);
            n--;
        }
        else{
            multiply(mat,mat);
            n = n / 2;
        }
    }
    long long ans = (1LL)*a*identity[0][0] + b*identity[1][0];
    ans %= MOD;
    return ans;
}

int solve(int n) {
    return getfib(1,1,n);
}
