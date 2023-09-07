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
bool issafe(int** arr, int x, int y, int n){
    if(x<n&&y<n&&arr[x][y]==1){
        return true;
    }
    return false;
}
bool ratinmaze(int** arr, int x, int y, int n, int** sol){
    if(x==n-1&&y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n)){
        if(ratinmaze(arr,x+1,y,n,sol)){
            sol[x][y]=1;
            return true;
        }
        if(ratinmaze(arr,x,y+1,n,sol)){
            sol[x][y]=1;
            return true;
        }
        sol[x][y]=0;
        return false;

    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int**arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int [n];

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int** sol=new int*[n];
    for(int i=0;i<n;i++){
        sol[i]=new int [n];
        for(int j=0;j<n;j++){
            sol[i][j]=0;
        }

    }
    if(ratinmaze(arr,0,0,n,sol)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }




    

}
