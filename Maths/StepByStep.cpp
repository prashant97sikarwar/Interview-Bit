//problem Link:- https://www.interviewbit.com/problems/step-by-step/

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int target = abs(n);
    int k = 0;
    while (target > 0){
        k++;
        target -= k;
    }
    return (target % 2 == 0) ? k : k+1+k%2;
}
