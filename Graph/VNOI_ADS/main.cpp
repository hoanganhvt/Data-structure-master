#include<iostream>
#include<deque>
#include<vector>
using namespace std;

bool visited[10000];
struct Graph{
	int V;
	vector<int>*adj;
};

void newGraph(Graph *g,int N){
	g->V = N;
	g->adj = new vector<int>[N+1];
};

void dfs(int u,Graph g){
	visited[u] = 1;
	for(int i = 0; i < g.adj[u].size();i++){
		int v = g.adj[u][i];
		if(!visited[v]){
			dfs(v,g);
		}
	}
}

int main(){
	int N,M;
	cin >> N >> M;
	Graph g;
	newGraph(&g,N);
	for(int i = 0; i < M;i++){
		int u,v;
		cin >> u >> v;
		g.adj[u].push_back(v);
		g.adj[v].push_back(u);
	}
	int k = 0;
	for(int i = 1; i <= N;i++){
		if(!visited[i]){
			k++;
			dfs(i,g);
		}
	}
	cout << k << endl;
	cout << M-N+k << endl;
}
