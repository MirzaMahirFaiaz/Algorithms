//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;
typedef pair <int,int> pr;
typedef vector <pr> vpr;
vector<int> res;
vector<vpr> graph,tempGraph;

int inft = INT_MAX, sum = 0, n;
bool visited[100];

priority_queue<pair<int,int>> que1;
priority_queue<pair<int,vector<vpr>>> que2;


void rowReduce(vector<vpr> &gr, int &summ)
{
    for(int i = 0; i < n; i++)
    {
        int mn = gr[i][0].second;
        for(int j = 1; j < n; j++)
            mn = min(mn,gr[i][j].second);
        if(mn==inft || mn==0)
            continue;
        for(int j=0; j < n; j++)
            if(gr[i][j].second!=inft)
             gr[i][j].second -= mn;
        summ+=mn;
    }
}

void colReduce(vector<vpr> &gr, int &summ)
{
    for(int i = 0; i < n; i++)
    {
        int mn = gr[0][i].second;
        for(int j = 1; j < n; j++)
            mn = min(mn,gr[j][i].second);
        if(mn==inft|| mn==0)
            continue;
        for(int j=0; j < n; j++)
            if(gr[j][i].second!=inft)
             gr[j][i].second -= mn;
        summ+=mn;
    }
}

void TempGraphInit(vector<vpr> &vec, int src, int dest)
{
    for(int i=0; i<n; i++)
    {
        vec[src][i].second = inft;
        vec[i][dest].second = inft;
    }
    for(int i=0;i<res.size();i++)
         vec[dest][res[i]].second = inft;
}

void TSP()
{
    rowReduce(graph,sum);
    colReduce(graph,sum);
    que1.push(make_pair(-sum,0));
    que2.push(make_pair(-sum,graph));
    while(!que1.empty())
    {
        int node = que1.top().second;
        graph = que2.top().second;
        sum = -1*que1.top().first;

        que1.pop();
        que2.pop();

        visited[node]=true;
        res.push_back(node);

        while(!que1.empty()){
            que1.pop();
            que2.pop();
        }
        for(int j = 0; j < n; j++)
        {
            if(visited[j] || node == j)
                continue;
            tempGraph=graph;
            TempGraphInit(tempGraph,node,j);
            int sum2=0;
            colReduce(tempGraph,sum2);
            rowReduce(tempGraph,sum2);
            sum2 += sum+graph[node][j].second;
            que1.push(make_pair(-sum2,j));
            que2.push(make_pair(-sum2,tempGraph));
        }
    }
    res.push_back(0);

}


int main()
{
    cout<<"Enter number of nodes: ";
    cin>>n;
    graph.resize(n+5);

    cout<<"\nEnter cost matrix:\n\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"cost["<<i+1<<"]["<<j+1<<"] = ";
            if(i==j)
            {
                graph[i].push_back(make_pair(j,inft));
                cout<<"inf"<<endl;
                continue;
            }
            int inp;
            cin>>inp;
            graph[i].push_back(make_pair(j,inp));
        }
    }
    TSP();
    cout<<"\nTotal Travelling Cost: "<<sum<<endl;
    cout<<"Travelling Path = "<<res[0]+1;
    for(int i = 1; i < res.size(); i++)
        cout<<" -> "<<res[i]+1;
    cout<<endl;

    return 0;
}
//5
//20 30 10 11 15 16 04 02 03 05 02 04 19 06 18 03 16 04 07 16

