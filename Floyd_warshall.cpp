//@author MIRZA MAHIR FAIAZ, Dept. of CSE, AUST
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
using namespace std;

vector<int> graph[100], dist[100];
int infi = INT_MAX;

void initialize(int v)
{
    int i,j;
    for(i=0;i<v;i++) {
        for(j=0;j<v;j++)
            graph[i].push_back(infi);
    }
}

void floyd_warshall(int v)
{
    int i,j,k;
    for(i=0;i<v;i++)
        dist[i]=graph[i];
	for(k=0;k<v;++k) {
		for(i=0;i<v;++i) {
			for(j=0;j<v;++j)
			{
				if(dist[i][k]==infi || dist[k][j]==infi)
					continue;
				else if(dist[i][k]+dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	for(i=0;i<v;++i)
    {
		if(dist[i][i] < 0)
		{
			cout<<"Negative edge weight cycle is present\n";
			return;
		}
	}
	for(i=1;i<v;++i)
	{
		for(j=0;j<v;++j)
			cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<endl;
        cout<<endl;
	}

}

int main()
{
    int V,i,j;
    cout<<"Enter how many vertices : ";
     cin >> V;
    initialize(V);
    for(i=0;i<V;i++) {
        for(j=0;j<V;j++)
            cin>>graph[i][j];
    }
	floyd_warshall(V);
	return 0;
}

/*
6
0 1 4 99999 99999 99999
99999 0 4 2 7 99999
99999 99999 0 3 4 99999
99999 99999 99999 0 99999 4
99999 99999 99999 3 0 99999
99999 99999 99999 99999 5 0
*/
