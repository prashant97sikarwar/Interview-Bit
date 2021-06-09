//Problem Link:- https://www.interviewbit.com/problems/equal-average-partition/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > avgset(vector<int> &A) {
    int m=A.size()/2;

    sort(A.begin(),A.end());
    vector<unordered_set<int>> dp(m+1);
    
    dp[0].insert(0);

    for(auto num: A){
        for(int i=m;i>0;i--){
            for(auto t:dp[i-1]){
                dp[i].insert(t+num);
            }
        }    
    }
    
    int sum=0;
    for(int x:A) sum+=x;
    
    for(int i=1;i<=m;i++){
        if(!((sum*i)%A.size()) && (dp[i].find((sum*i)/A.size())!=dp[i].end())){
            int req_sum = (sum*i)/A.size();
            int n=i, ind=0;
            vector<int> fh;
            while(req_sum && ind<A.size() && n){
                if(dp[n-1].find(req_sum-A[ind]) != dp[n-1].end()){
                    fh.push_back(A[ind]);
                    req_sum -= A[ind];
                    n--;
                }
                ind++;
            }
            if(fh.size()!=i)   continue;
            
            vector<int> sh;
            // sort(fh.begin(), fh.end());
            set_difference(A.begin(), A.end(), fh.begin(), fh.end(), inserter(sh, sh.begin()));
            return {fh,sh};
        }
    }
    return {};
}