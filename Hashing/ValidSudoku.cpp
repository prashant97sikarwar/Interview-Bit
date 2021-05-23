//Problem Link:- https://www.interviewbit.com/problems/valid-sudoku/

#include<bits/stdc++.h>
using namespace std;

bool helper(vector<char> arr){
    unordered_map<char,int> ump;
    for(int i=0;i<arr.size();i++){
        if (arr[i] == '.'){
            continue;
        }
        ump[arr[i]]++;
        if (ump[arr[i]] > 1){
            return true;
        }
    }
    return false;
}

int isValidSudoku(const vector<string> &nums) {
    for(int i=0;i<9;i++){
        vector<char> row;
        for(int j=0;j<9;j++){
            row.push_back(nums[i][j]);
        }
        if (helper(row)){
            return 0;
        }
    }
    for(int i=0;i<9;i++){
        vector<char> col;
        for(int j=0;j<9;j++){
            col.push_back(nums[j][i]);
        }
        if (helper(col)){
            return 0;
        }
    }
    
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            vector<char> square;
            for(int l=i;l<i+3;l++){
                for(int r=j;r<j+3;r++){
                    square.push_back(nums[l][r]);
                }
            }
            if (helper(square)){
                return 0;
            }
        }
    }
    return 1;
}
