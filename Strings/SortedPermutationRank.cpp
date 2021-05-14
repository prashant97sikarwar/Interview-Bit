//Problem Link:- https://www.interviewbit.com/problems/sorted-permutation-rank/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lld;
const lld NN = 500000;
const lld mod = 1000003;
lld fact[NN+7];
void init(lld n=NN, lld m=mod)
{
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=i*fact[i-1]%m;
}

lld getRank(char c)
{
    if(c>='a')
        return c-'a'+26;
    return c-'A';
}

int findRank(string A) {
    lld ans=0,n=A.size();
    lld alp[52]={};
    init();
    for(int i=n-1;i>=0;i--)
    {
        lld less=0;
        for(int j=0;j<getRank(A[i]);j++)
            less+=alp[j];
        
        alp[getRank(A[i])]++;
        ans=(ans+fact[n-i-1]*less)%mod;
    }
    
    return ans+1;
}
