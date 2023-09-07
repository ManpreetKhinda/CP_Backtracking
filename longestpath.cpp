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

int solve(vector<vector<int>> &mat, int i, int j, int x,int y, int n, int m,
int curr=0, int ans=-1){
    if(i==x && j==y){
        if(curr>ans){
            ans=curr;
        }
        return ans;
    }
    
    mat[i][j]=0;
    if(j!=m-1 && mat[i][j+1]==1){
        ans=solve(mat,i,j+1,x,y,n,m,curr+1,ans);
    }
    if(i!=n-1 && mat[i+1][j]==1){
        ans=solve(mat,i+1,j,x,y,n,m,curr+1,ans);
    }
    if(j!=0 && mat[i][j-1]==1){
        ans=solve(mat,i,j-1,x,y,n,m,curr+1,ans);
    }
    if(i!=0 && mat[i-1][j]==1){
        ans=solve(mat,i-1,j,x,y,n,m,curr+1,ans);
    }
    mat[i][j]=1;
    return ans;
}
int main(){
    vector<vector<int> > mat = { { 1, 1, 1, 1 },
                                 { 1, 1, 0, 1 },
                                 { 1, 1, 1, 1 } };
    cout<<solve(mat,0,0,2,3,3,4);
}