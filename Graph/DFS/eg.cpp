#include<iostream>
#include<vector>

using namespace std;

struct graph{
	int N;
	vector<int>*adj;
};

void addEdg(graph *g,int u,int v){
	bool good = true;
	for(int i = 0;i < g->adj[u].size();i++){
		if(g->adj[u][i] == v){
			good = false;
			break;
		}
	}
	if(good){
		g->adj[u].push_back(v);
	}
}

bool visited[10000];
void dfs(graph g,int u){
	visited[u] = 1;
	for(int i = 0; i < g.adj[u].size();i++){
		int v = g.adj[u][i];
		if(!visited[v]){
			printf("visited %d ",v);
			dfs(g,v);
		}
	}
}
int main(){
	graph g;
	int edgNum;
	cin >> g.N >> edgNum;
	g.adj = new vector<int>[g.N];
	for(int i = 0; i < edgNum;i++){
		int u,v;
		cin >> u >> v;
		addEdg(&g,u,v);
	}
	/*for(int i = 0; i < g.N;i++){
		printf("%d: ",i);
		for(int j = 0; j < g.adj[i].size();j++){
			printf("%d ",g.adj[i][j]);
		}
		printf("\n");
	}*/
	dfs(g,0);
}

