#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;


struct graph{
	int N;
	vector<int>*edge;
};

void addEdg(graph *g,int u,int v){
	bool good = true;
	for(int i = 0;i < g->edge[u].size();i++){
		if(g->edge[u][i] == v){
			good = false;
			break;
		}
	}
	if(good){
		g->edge[u].push_back(v);
	}
}

void bfs(graph g,int start){
	deque <int>q;
	bool *visited = new bool[g.N+1];
	q.push_back(start);
	visited[start] = 1;
	printf("Visited %d\n",start);
	while(!q.empty()){
		for(int i = 0; i < g.edge[q.back()].size();i++){
			if(!visited[g.edge[q.back()][i]]){
				q.push_front(g.edge[q.back()][i]);
				visited[g.edge[q.back()][i]] = 1;
				printf("visited %d\n",g.edge[q.back()][i]);

			}
		}
		q.pop_back();
	}
}
int main(){
	graph g;
	cin >> g.N;
	g.edge = new vector<int>[g.N];
	int edNum;
	cin >> edNum;
	for(int i = 0; i < edNum;i++){
		int u,v;
		cin >> u >> v;
		addEdg(&g,u,v);
	}
	/*for(int i = 0; i < g.N;i++){
		printf("%d: ",i);
		for(int j = 0; j < g.edge[i].size();j++){
			cout << g.edge[i][j] << " ";
		}
		cout << endl;
	}*/
	bfs(g,0);
}
