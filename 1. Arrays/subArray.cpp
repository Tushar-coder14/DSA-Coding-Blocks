#include <iostream>
using namespace std;

int main(){
    int a[]  = {1,2,3};
    int n = sizeof(a)/sizeof(int);
    int count = 0;
    int k=3;

    for(int i=0 ; i<n ; i++){
        int sum = 0;
        for(int j=i ; j<n ; j++){
            sum += a[j];
            if(sum == k){
                count++;
                cout<<"subarray :{"<<i<<","<<j<<"}"<<endl;
                for(int k=i ; k<=j ; k++){
                    cout<<a[k]<<" ";
                }
                cout<<endl;
            }
        }
    }
    cout<<count;

    return 0;
}