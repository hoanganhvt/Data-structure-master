#include<iostream>
#include<set>
#include<vector>

using namespace std;

typedef pair<int,int> II; 


int Length[10000];
bool explored[10000];
vector<II>*Adj;
void Dijstra(II Start){
	set<II>Q;
	explored[Start.second] = 1;
	Q.insert(Start);
	while(Q.size()){
		II Point = *Q.begin();
		Q.erase(Point);
		int u = Point.second;
		for(int i = 0; i < Adj[u].size();i++){
			int v = Adj[u][i].second;
			int newL = Adj[u][i].first;
			if(!explored[v]){
				explored[v] = 1;
				Length[v] = Length[u]+newL;
				Q.insert(II(Length[v],v));
			}
			else if(Length[u]+newL < Length[v]){
				Length[v] = Length[u]+newL;
				Q.insert(II(Length[v],v));
			}
		}
	}
}
int main(){
	int N,t;
	cin >> N >> t;
	Adj = new vector<II>[N+1];
	for(int i = 0; i < t;i++){
		int u,v,cost;
		cin >> u >> v >> cost;
		Adj[u].push_back(II(cost,v));
	}
	Dijstra(II(0,1));
	for(int i = 1; i <= N;i++){
		cout << Length[i] << " ";
	}
	cout << endl;
	system("pause");
}