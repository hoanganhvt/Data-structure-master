#include<iostream>
#include<algorithm>
#include<deque>
#include<cstdio>
#include<vector>
using namespace std;

struct Path{
	int dest;
	int cost;
};

struct Graph{
	int V;
	vector<Path>*Adj;
};

Graph newGraph(Graph g,int N){
	g.V = N;
	g.Adj = new vector<Path>[N+1];
	return g;
}

void addEdg(Graph *g,int u,int v,int cost){
	g->Adj[u].push_back(Path{v,cost});
	g->Adj[v].push_back(Path{u,cost});
}

bool visited[10000];
int Length[10000];
int shortestPath(Graph g,int Start,int End){
	deque<int>q;
	q.push_back(Start);
	while(!q.empty()){
		int u = q.back();
		printf("dang o %d \n",u);
		cout << u << endl;
		for(int i = 0; i < g.Adj[u].size();i++){
			int v = g.Adj[u][i].dest;
			if(!visited[v]){
				if(Length[v] == 0){
					q.push_back(v);
					Length[v] = Length[u]+g.Adj[u][i].cost;
				}
				else{
					q.push_back(v);
					Length[v] = min(Length[v],g.Adj[u][i].cost);
				}
			}
		}
		visited[u] = 1;
		q.pop_front();
	}
	return Length[End];
}
int main(){
	int N,m;
	cin >> N >> m;
	Graph g = newGraph(g,N);
	for(int i = 0;i<m;i++){
		int u,v,c;
		cin >> u >> v >> c;
		addEdg(&g,u,v,c);
	}
	int Start,End;
	cin >> Start >> End;
	cout << shortestPath(g,Start,End) << endl;
}
