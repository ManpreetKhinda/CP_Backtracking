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
    bool issafe(bool graph[101][101], int col[], int color, int node, int n ){
        for(int  k=0;k<n;k++){
            if(k!= node && col[k]==color && graph[k][node])return false;
        }
        return true;
    }
    bool solve(int node, bool graph[101][101],  int m, int N, int col[]){
        if(node==N)return true;
        for(int i=1;i<=m;i++){
            if(issafe(graph,col,i,node,N)){
                col[node]=i;
                if(solve(node+1, graph, m,N,col))return true;
                col[node]=0;
            }
        }
        return false;
    }
    public:
    bool graphcoloring(bool graph[101][101],int m, int N){
        int col[N]={0};
        return solve( 0, graph, m,N, col);

    }
};