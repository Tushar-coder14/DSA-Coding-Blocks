#include<iostream>
using namespace std;

int findElement(int arr[], int key, int n){
	for(int i=0; i<n; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}

int main() {
	int n;
	int arr[n];
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<findElement(arr, key , n);
	return 0;
}