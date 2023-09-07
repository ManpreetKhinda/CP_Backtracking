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
    bool issafe(int row,int col, vector<string> &temp, int n){
        int r=row;
        int c=col;
        while(r>=0 && c>=0){
            if(temp[r][c]=='Q')return false;
            r--;c--;
        }
        r=row;c=col;
        while(r<n && c>=0){
            if(temp[r][c]=='Q')return false;
            r++;c--;
        }
        c=col;r=row;
        while(col>=0){
            if(temp[r][c]=='Q')return false;
            c--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string> &temp, int col,int n){
        if(col==n){
            ans.push_back(temp);
            return ;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,temp,n)){
                temp[row][col]='Q';
                solve(ans,temp,col+1,n);
                temp[row][col]='.';
            }
        }
    }
    public:
    vector<vector<string>>Nqueen(int n){
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)temp[i]=s;
        solve(ans,temp,0,n);
        return ans;
    } 
};
class Solution2{
    private:
    bool solve(int col,vector<bool>&left, vector<bool>& lowerdiagonal, vector<bool>&upperdiagonal,int n, vector<vector<string>>&ans,
    vector<string> &temp){
        if(col==n){
            ans.push_back(temp);
            return ;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1+col-row]==0){
                temp[row][col]='Q';
                left[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                solve(col+1, left,lowerdiagonal,upperdiagonal, n,ans,temp);
                temp[row][col]='.';
                left[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
            }
        }
    }
    public:
    vector<vector<string>> Nquens(int n){
        vector<vector<string>>ans;
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)temp[i]=s;
        vector<bool> left(n,0);
        vector<bool> lowerdiagonal(2*n-1,0);
        vector<bool> upperdiagonal(2*n-1,0);
        solve(0, left,lowerdiagonal, upperdiagonal, n,ans,temp);
        return ans;
    }
};