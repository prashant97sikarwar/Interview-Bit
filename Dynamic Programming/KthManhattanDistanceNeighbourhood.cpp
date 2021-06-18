//Problem link:- https://www.interviewbit.com/old/problems/kth-manhattan-distance-neighbourhood/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > solve(int A, vector<vector<int> > &B) {
    if(A==0)
    return B;

    int r = B.size();
    int c = B[0].size();
    
    vector<vector<int>> C=B;
    
    for(int m=1;m<=A;m++){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                    
                int neigh_x[] = {0,1,0,-1};
                int neigh_y[] = {1,0,-1,0};
                
                int max_neigh = B[i][j];
                
                for(int t=0;t<4;t++){
                    int neigh_pos_x = i+neigh_x[t];
                    int neigh_pos_y = j+neigh_y[t];
                    if(neigh_pos_x>=0 and neigh_pos_x<r and neigh_pos_y>=0 and neigh_pos_y<c)
                        max_neigh = max(max_neigh,B[neigh_pos_x][neigh_pos_y]);
                }
    
                C[i][j]=max_neigh;
                
            }
        }
        B=C;
    }
    return C;
}
