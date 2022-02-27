//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
vector<int>weight(100),profit(100),knapsack[100];
int main()
{
   int max_weight,total,i,j,value;
    cout<<"Enter the maximum weight of capacity :"<<endl;
    cin>>max_weight;
    cout<<"Enter the number of total items :"<<endl;
    cin>>total;
    cout<<"Enter the elements of weight and profit :"<<endl;
    for(i=1; i<=total; i++)
    {
       cin>>weight[i]>>profit[i];

    }
    for(i=0;i<=total;i++)
    {
        for(j=0;j<=max_weight;j++)
        {
            knapsack[i].push_back(0);
        }
    }
    for(i=1;i<=total;i++)
    {
        for(j=0;j<=max_weight;j++)
        {
            if(i==0 || j==0)
            {
                knapsack[i][j]=0;
            }
            else if(weight[i]<=j)
            {
                knapsack[i][j]=max(profit[i]+knapsack[i-1][j-weight[i]],knapsack[i-1][j]);
            }
            else
            {
                knapsack[i][j]=knapsack[i-1][j];
            }
        }
        value=knapsack[total][max_weight];
    }
    for(i=0; i<=total; i++)
    {
        for(j=0; j<=max_weight; j++)
        {
            cout<<knapsack[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nThe maximum value that can be stored in knapsack is "<<value<<endl;
    cout<<"Selected values are :"<<endl;
    i=total,j=max_weight;
    while(i>0 && j>0)
    {
        if(knapsack[i][j]==knapsack[i-1][j])
        {
            cout<<i<<" not selected"<<endl;
            i=i-1;
        }
        else
        {
            cout<<i<<" selected"<<endl;
          j=j-weight[i];
          i=i-1;

        }
    }

}
