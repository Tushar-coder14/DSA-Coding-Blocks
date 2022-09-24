#include <iostream>
using namespace std;

int main(){
    int a[] = {1,3,6,7,10,14};
    int n = sizeof(a)/sizeof(int);
    int key = 11;
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid] == key){
            cout<<mid;
            break;

        }
        else if(a[mid]<key){
            s = mid+1;
        }
        else{
            e = mid - 1;
        }
    }
    if(s>e){
        cout<<"Key not found";
    }
    return 0;
}