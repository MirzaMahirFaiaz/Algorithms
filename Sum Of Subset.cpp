//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;

void sumOfSubset(int s, int k, int r) {
   x[k] = 1;
   if(s + w[k] == m) {
        for(int i=0; i<=k; i++){
            if(x[i] == 1)
                cout<<w[i]<<" ";
        }
        cout<<endl;
   }
   else if(s+w[k]+w[k+1]<=m) sumOfSubset(s+w[k],k+1,r-w[k]);
   if(s+r-w[k]>=m&&s+w[k+1]<=m) {
        x[k] = 0;
        sumOfSubset(s,k+1,r-w[k]);
   }
}

int main() {
    cout<<"Enter number of elements: ";
    cin >> n;
    int sum=0;
    cout<<"Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    cout<<"Enter desired sum: ";
    cin >> m;
    sort(w,w+n);
    sumOfSubset(0,0,sum);
}
/*
6
5 10 12 13 15 18
30
*/
