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
    bool solve(vector<vector<char>> &grid){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(grid,i,j,c)){
                            if(solve(grid))return true;
                            else grid[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>&grid, int i,int j, char c){
        for(int k=0;k<9;k++){
            if(grid[k][j]==c)return false;
            if(grid[i][k]==c)return false;
            if(grid[3*(i/3)+k/3][3*(j/3)+k%3]==c)return false;
            return true;
        }
    }
    public:
    void sudoku(vector<vector<char>>&grid){
        solve(grid);
    }
};