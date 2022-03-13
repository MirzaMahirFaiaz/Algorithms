//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
int x[2002];

void print(int n) {
    cout<<"\nColumns: ";;
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    cout<<"\nChess Board:\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            if(j==x[i]) cout<<"Q"<<i<<"\t";
            else cout<<"0\t";
        }
        cout<<endl;
    }
}

bool place(int k, int i) {
    for(int j = 1; j <= k-1; j++) {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return false;
    }
    return true;
}

void nQueens(int k, int n) {
   for(int i = 1; i <= n; i++) {
        if(place(k,i)) {
            x[k] = i;
            if(k == n){
                    cout<<"i "<<i<<endl;
                print(n);
            }
            else
             nQueens(k+1,n);
        }
   }
}

int main()
{

    ll t,i,j,n;
    cout<<"Enter the value of N = ";
     cin >> n;
    nQueens(1,n);
return 0;
}
