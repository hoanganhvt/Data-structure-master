#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int N;
void constructTree(int segTree[],int arr[],int id,int l = 0,int r = N-1){
	if(l == r){
		segTree[id] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	constructTree(segTree,arr,id*2+1,l,mid);
	constructTree(segTree,arr,id*2+2,mid+1,r);
	segTree[id] = min(segTree[id*2+1],segTree[id*2+2]);
}

int querry(int segTree[],int LEFT,int RIGHT,int id,int l,int r){
	if(l > LEFT || r < RIGHT){
		return INT_MAX;
	}
	if(l >= LEFT && r <= RIGHT){
		return segTree[id];
	}
	int mid = (l+r)/2;
	return min(querry(segTree,LEFT,RIGHT,2*id+1,l,mid),querry(segTree,LEFT,RIGHT,2*id+2,mid+1,r));
}

int main(){
	cin >> N;
	int arr[N];
	int segTree[2*N-1];
	for(int i = 0; i < N;i++){
		cin >> arr[i];
	}
	constructTree(segTree,arr,0);
	int l,r;
	cin >> l >> r;
	int result = querry(segTree,l,r,0,0,N-1);
	cout << result << endl;
	system("pause");
}