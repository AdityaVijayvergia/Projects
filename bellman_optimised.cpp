#include <iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

struct graph{
	int no,w;
};
//typedef struct graph graph;
int main()
{
	int n,m;
	cin>>n>>m;
	graph gr;
	vector <graph> g[n+1];
	int weight[n+1],pre[n+1],a,b;
	for(int i=0;i<m;i++){
		cin>>a;
		cin>>gr.no>>gr.w;
		g[a].push_back(gr);
		b=gr.no;
		gr.no=a;
		g[b].push_back(gr);
	}
	for(int i=1;i<n+1;i++){
		weight[i]=INFINITY;
		pre[i]=-1;
	}
	weight[1]=0;
	queue <int> v;
	v.push(1);
	int changed=1;
	
	while(!v.empty()){
		int j=v.front();
		v.pop();
		for(int k=0;k<g[j].size();k++){
			if(weight[j]+g[j][k].w<weight[g[j][k].no]){
				weight[g[j][k].no]=weight[j]+g[j][k].w;
				v.push(g[j][k].no);
			}
		}
	}
	for(int i=2;i<n+1;i++){
		if(weight[i]==INFINITY)
			cout<<2e9<<" ";
		else
			cout<<weight[i]<<" ";
	}
    return 0;
}
