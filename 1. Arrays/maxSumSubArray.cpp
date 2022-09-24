#include <iostream>
using namespace std;

int main(){
    int a[] = {1,8,-5,13,-10,8};
    int n = sizeof(a)/sizeof(int);
    int max_sum = INT_MIN;
    int start,end;

    for(int i=0 ; i<n ; i++){
        int sum = 0;
        for(int j=i ; j<n ; j++){
            sum += a[j];
            if(sum>max_sum){
                max_sum = sum;
                start = i;
                end = j;
            }
        }
    }

    cout<<"Subarray with Max Sum : ";
    for(int k = start ; k<=end ; k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    cout<<"Max Sum: "<<max_sum<<endl;

    return 0;
}