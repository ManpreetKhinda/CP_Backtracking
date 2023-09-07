#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution{
    private:
    public:
    void recursive(vector<vector<int>>&ans,vector<int>&temp,vector<bool>&vis, vector<int>&nums){
        int n=nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i]=1;
                recursive(ans,temp,vis,nums);
                vis[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>>permutations(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool>vis(n,0);
        recursive(ans,temp,vis,nums);
        return ans;
    }
};
class solution2{
    private:
    void recur(vector<vector<int>>&ans, vector<int>&nums, int index){
        int n=nums.size();
        if(index==n){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[index],nums[i]);
            recur(ans,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>&nums){
        vector<vector<int>> ans;
        recur(ans,nums,0);
        return ans;
    }
};