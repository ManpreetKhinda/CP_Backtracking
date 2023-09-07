#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define size 4

bool issafe(int arr[size][size],int x,int y, int n){
    if(x<n&&y<n&& (arr[x][y]==1)){
        return true;
    }
    return false;
}
bool rat_inmaze(int arr[size][size],int x, int y,int n,int sol[size][size]){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n)){
        sol[x][y]=1;
        if(rat_inmaze(arr,x+1,y,n,sol)){
            
            return true;
        }
        if(rat_inmaze(arr,x,y+1,n,sol)){
            
            return true;
        }
        sol[x][y]=0;
        return false;

    }
    return false;

}
int main(){
    int M[4][4] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {0, 1, 0, 0},
         {0, 1, 1, 1}};

    int S[4][4]={0};
    if(rat_inmaze(M,0,0,4,S)){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<S[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;

}
