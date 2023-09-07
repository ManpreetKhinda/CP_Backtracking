#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <ios>
using namespace std;
#define N 8

bool issafe(int x, int y, int sol[N][N]){
    return (x>=0 &&x<N &&y>=0 &&y<N && sol[x][y]==-1);
}
void printsol(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<" "<<setw(2)<< sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
int solveKT(){
    int sol[N][N];
    memset(sol,-1,sizeof sol);
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={2,1,-1,-2,-2,-1,1,2};
    sol[0][0]=0;
    if(solutil(0,0,1,sol,dx,dy)==0){
        return 0;
    }
    else{
        printsol(sol);
    }
}
int solutil(int x,int y, int movei,
int sol[N][N], int dx[8],int dy[8]){
    int k,next_x, next_y;
    if(movei==N*N){
        return 1;
    }
    for(int k=0;k<8;k++){
        next_x=x+dx[k];
        next_y=y+dx[k];
        if(issafe(next_x, next_y, sol)){
            sol[next_x][next_y]=movei;
            if(solutil(next_x,next_y,movei+1,sol,dx,dy)){
                return 1;
            }
            else{
                sol[next_x][next_y]=-1;
            }
        }
    }
    return 0;


}
int main(){
    solveKT();
    return 0;
}
