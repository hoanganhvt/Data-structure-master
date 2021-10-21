#include<iostream>
#include<climits>
using namespace std;
//querry max value
void constructTree(int segTree[],int arr[],int id,int l,int r){
	if(l == r){
		segTree[id] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	constructTree(segTree,arr,id*2+1,l,mid);
	constructTree(segTree,arr,id*2+2,mid+1,r);
	segTree[id] = max(segTree[id*2+1],segTree[id*2+2]);
}


int Querry(int segTree[],int LEFT,int RIGHT,int l,int r,int id){
	if(r < LEFT || l > RIGHT){
		return INT_MIN;
	}
	if(l <= LEFT && r <= RIGHT){
		return segTree[id];
	}
	int mid = (l+r)/2;
	return max(Querry(segTree,LEFT,RIGHT,l,mid,id*2+1),Querry(segTree,LEFT,RIGHT,mid+1,r,id*2+2));
}
int main(){
	int N;
	cin >> N;
	int segTree[2*N-1];
	int arr[N];
	for(int i = 0; i < N;i++){
		cin >> arr[i];
	}
	constructTree(segTree,arr,0,0,N-1);
	int result = Querry(segTree,0,N-1,0,N-1,0);
	cout << result << endl;
	system("pause");
}