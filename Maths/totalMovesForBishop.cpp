//Problem Link:- https://www.interviewbit.com/problems/total-moves-for-bishop/

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m) {
    int i = n,j = m;
    int res = 0;
    while (i >= 1 && j >= 1 && i <= 8 && j <= 8){
        i--;
        j++;
        res++;
    }
    i = n,j = m;
    while (i >= 1 && j >= 1 && i <= 8 && j <= 8){
        i--;
        j--;
        res++;
    }
    i = n,j = m;
    while (i >= 1 && j >= 1 && i <= 8 && j <= 8){
        i++;
        j--;
        res++;
    }
    i = n,j = m;
    while (i >= 1 && j >= 1 && i <= 8 && j <= 8){
        i++;
        j++;
        res++;
    }
    return res-4;
}
