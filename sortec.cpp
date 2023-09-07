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
// reverse a string
void reverse(string s){
    if(s.length()==0){
        return ;
    }
    string ros=s.substr(1);
    reverse(ros);
    cout<<s[0];

}
//replace pi with 3.14 in a string
void replacepi(string s){
    if(s.length()==0){
        return ;
    }
    if(s[0]=='p' &&s[1]=='i'){
        cout<<"3.14";
        replacepi(s.substr(2));

    }
    else{
        cout<<s[0];
        replacepi(s.substr(1));
    }
    
}

//tower of hanoi
void towerofhanoi(int n, char src, char des, char helper){
    if(n==0){
        return ;
    }
    towerofhanoi(n-1,src,helper,des);
    cout<<src<<"to"<<des<<endl;
    towerofhanoi(n-1,helper,des,src);
    cout<<helper<<"to"<<des<<endl;

}
//remove duplicates froms tring
string removedup(string s){
    if(s.length()== 0){
        return "";
    }
    char ch=s[0];
    string ans=removedup(s.substr(1));
    if(ch==ans[0]){
        return  ans;
    }
    return (ch+ans);
}
// move x to the end
string xtoend(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=xtoend(s.substr(1));
    if(ch=='X'){
        return ans+'X';
    }
    return ch+ans;}
//generate all substrings of a strings
void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}
//print all possible words from phone digits
string keypadarr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code=keypadarr[ch-'0'];
    string ros=s.substr(1);
    for(int i=0;i<code.length();i++){
        keypad(ros,ans+code[i]);
    }


}



// int main(){
//     cout<<xtoend("AXXBDXCEFXHIX");
//     return 0;
// }
//permutation of a string
void permutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutation(ros,ans+ch);
    }
    


}
// int main(){
//     permutation("ABCD","");
// }
//number of paths from start to end in a board game
int countpath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<7;i++){
        count+=countpath(s+i,e);
    }
    return count;
}
//possible path in a unobstructed maze
int maze(int n, int i, int j)
{
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n||j>=n){
        return 0;
    }
    return (maze(n,i+1,j)+maze(n,i,j+1));
}
// int main(){
//     cout<<maze(3,0,0);
//     return 0;
// }
//tiling a 2*n with 2*1
int ways(int n){
    if(n==0 ||n==1){
        return n;
    }
    return ways(n-1)+ways(n-2);

}
// friends pairing problems
int pairs(int n){
    if(n==0||n==1||n==2){
        return n;
    }
    return pairs(n-1)+pairs(n-2)*(n-1);

}
//0-1 knapsack
int knapsack(int value[],int wt[], int n, int W){
    if(n==0||W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(value,wt,n-1,W)
    }
    knapsack(value,wt,n-1,W-wt[n-1])+knapsack(value,wt,n-1,W);
}

void dec(int n){
    if(n==1){
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
void inc(int n){
    if(n==1){
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
int firstocc(int arr[],int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);

}
int lastocc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    int restarr=lastocc(arr,n,i+1,key);
    if(restarr!=-1){
        return restarr;

    }
    if(arr[i]==key){
        return i;

    }
    return -1;

}

bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool restarr=sorted(arr+1, n-1);
    return (arr[0]<arr[1] && restarr);
    }


