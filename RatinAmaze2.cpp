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

class solution{
    private:
    void solve(int i,int j, vector<vector<bool>>&grid, int n, vector<string>&ans, vector<vector<bool>>&vis,string&s, int dr[],int dc[]){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        string move="DLRU";
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(ncol>=0 && ncol<n && nrow<n && nrow>=0 && !vis[nrow][ncol] && grid[nrow][ncol]){
                vis[nrow][ncol]=1;
                solve(nrow,ncol,grid,n,ans,vis,s+move[k],dr,dc);
                vis[nrow][ncol]=0;
            }
        }
    }
    public:
    vector<string> ratinamzae(vector<vector<bool>>&grid, int n){
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vector<string> ans;
        string s="";
        int dr[4]={1,0,0,-1};
        int dc[4]={0,-1,1,0};
        if(grid[0][0])solve(0,0,grid, n,ans,vis,s,dr,dc);
        return ans;
        
    }
};