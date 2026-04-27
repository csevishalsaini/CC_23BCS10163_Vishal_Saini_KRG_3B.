#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>&nums, int i, int j,vector<vector<int>>&t ){
        if(i == nums.size()-1 && j == nums[0].size()-1){
            if(nums[i][j] == 0){
                return 1;
            }
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(i>nums.size()-1){
            return 0;
        }
        else if(j>nums[0].size()-1){
            return 0;
        }
        if(nums[i][j] == 1){
            return 0;
        }
        return t[i][j] = solve(nums,i+1,j,t) + solve(nums,i,j+1,t);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> temp(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1, -1));
        return solve(obstacleGrid,0,0,temp);
    }
};
