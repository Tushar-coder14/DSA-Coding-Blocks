#include <iostream>
using namespace std;

int main(){
    int a[] = {0,1,-2,4,1,-3,5};
    int n = sizeof(a)/sizeof(int);
    int c_sum[100] = {0};
    int max_sum = INT_MIN;

    //To create c_sum Array:
    for(int i=1 ; i<n ; i++){
        c_sum[i] = a[i] + c_sum[i-1];
    }

    //To print c_sum Array:
    for(int i=0 ; i<n ; i++){
        cout<<c_sum[i]<<" ";
    }
    cout<<endl;


    for(int i=1 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int sum  = c_sum[j] - c_sum[i-1];
            if(sum > max_sum){
                max_sum = sum;
            }
        }
    }

    cout<<"Max Sum: "<<max_sum<<endl;
    return 0;
}